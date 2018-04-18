#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/raw_os_ostream.h"

#include "llvm/PassRegistry.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

#include "llvm/LLVMDependenceGraph.h"
#include "analysis/Offset.h"
#include "llvm/Slicer.h"
#include "llvm/analysis/PointsTo/PointsTo.h"
#include "llvm/analysis/ReachingDefinitions/ReachingDefinitions.h"
//#include "llvm/LLVMDG2Dot.h"
#include "llvm/analysis/DefUse.h"
//#include "analysis/PointsTo/PointerSubgraphValidator.h"
#include "analysis/PointsTo/PointsToFlowInsensitive.h"
#include "analysis/PointsTo/PointsToFlowSensitive.h"
#include "analysis/PointsTo/PointsToWithInvalidate.h"
#include "analysis/PointsTo/Pointer.h"

#include "llvm/analysis/PointsTo/PointsTo.h"

#include <set>
#include <memory>

class FunctionsPass : public llvm::ModulePass
{
public:
    static char ID;

    FunctionsPass()
        : llvm::ModulePass(ID)
    {
    }

    bool runOnModule(llvm::Module& M)
    {
        llvm::dbgs() << "Module " << M.getName() << "\n";
        m_module = &M;
        m_PTA.reset(new dg::LLVMPointerAnalysis(m_module));
        m_RD.reset(new dg::analysis::rd::LLVMReachingDefinitions(m_module, m_PTA.get()));
        buildDG();

        for (const auto& F : M) {
            llvm::dbgs() << "For F " << F.getName() << "\n";
            const std::string crit = "asserth";
            std::set<dg::LLVMNode *> callsites;
            bool ret = m_dg.getCallSites(crit.c_str(), &callsites);
            if (!ret) {
                llvm::errs() << "Did not find slicing criterion: "
                    << crit << "\n";
                break;
            }
        }

        return false;
    }

private:
    void computeEdges();
    void buildDG();
    void computeSlice();
    void computeFunctionSlice(llvm::Function* F, dg::LLVMDependenceGraph* F_dg);

private:
    std::unique_ptr<dg::LLVMPointerAnalysis> m_PTA;
    std::unique_ptr<dg::analysis::rd::LLVMReachingDefinitions> m_RD;
    dg::LLVMDependenceGraph m_dg;
    llvm::Module* m_module;
};

void FunctionsPass::computeEdges()
{
    m_RD->run<dg::analysis::rd::ReachingDefinitionsAnalysis>();

    dg::LLVMDefUseAnalysis DUA(&m_dg, m_RD.get(),
                               m_PTA.get());
    DUA.run(); // add def-use edges according that
    m_dg.computeControlDependencies(dg::CD_ALG::CLASSIC);
}

void FunctionsPass::buildDG()
{
    m_PTA->run<dg::analysis::pta::PointsToFlowInsensitive>();
    m_dg.build(m_module, m_PTA.get());
}


char FunctionsPass::ID = 0;
static llvm::RegisterPass<FunctionsPass> X("functions", "Functions");

