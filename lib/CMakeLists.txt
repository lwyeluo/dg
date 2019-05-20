include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Graphs)
include_directories(${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(LLVMdg MODULE
	analysis/Offset.cpp
	analysis/PointsTo/Pointer.cpp
	analysis/PointsTo/PointerAnalysis.cpp
	analysis/PointsTo/PointerSubgraphValidator.cpp
	analysis/ReachingDefinitions/BasicRDMap.cpp
	analysis/ReachingDefinitions/ReachingDefinitions.cpp
	analysis/ReachingDefinitions/Srg/SemisparseRda.cpp
	analysis/ReachingDefinitions/Srg/MarkerSRGBuilderFI.cpp
	analysis/ReachingDefinitions/Srg/MarkerSRGBuilderFS.cpp
	llvm/analysis/PointsTo/PointerSubgraph.cpp
	llvm/analysis/PointsTo/PointerSubgraphValidator.cpp
	llvm/analysis/PointsTo/Structure.cpp
	llvm/analysis/PointsTo/Globals.cpp
	llvm/analysis/PointsTo/Constants.cpp
	llvm/analysis/PointsTo/Instructions.cpp
	llvm/analysis/PointsTo/Calls.cpp
	llvm/analysis/ReachingDefinitions/LLVMRDBuilderSemisparse.cpp
	llvm/analysis/ReachingDefinitions/LLVMRDBuilderDense.cpp
	llvm/analysis/ReachingDefinitions/LLVMReachingDefinitions.cpp
	llvm/LLVMNode.cpp
	llvm/LLVMDependenceGraph.cpp
	llvm/LLVMDGVerifier.cpp
	llvm/analysis/Dominators/PostDominators.cpp
	llvm/analysis/DefUse/DefUse.cpp
        llvm/analysis/ThreadRegions/sources/MayHappenInParallel.cpp
        llvm/analysis/ThreadRegions/sources/ThreadRegion.cpp
        llvm/analysis/ThreadRegions/sources/Graphs/BlockGraph.cpp
        llvm/analysis/ThreadRegions/sources/Graphs/ControlFlowGraph.cpp
        llvm/analysis/ThreadRegions/sources/Graphs/CriticalSectionsBuilder.cpp
        llvm/analysis/ThreadRegions/sources/Graphs/FunctionGraph.cpp
        llvm/analysis/ThreadRegions/sources/Graphs/GraphBuilder.cpp
        llvm/analysis/ThreadRegions/sources/Graphs/ThreadRegionsBuilder.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/CallFuncPtrNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/CallNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/CallReturnNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/EntryNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/ExitNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/ForkNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/GeneralNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/JoinNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/LockNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/Node.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/NodeIterator.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/ReturnNode.cpp
        llvm/analysis/ThreadRegions/sources/Nodes/UnlockNode.cpp
)
target_compile_features(LLVMdg PRIVATE cxx_range_for cxx_auto_type)
set_target_properties(LLVMdg PROPERTIES COMPILE_FLAGS "-std=c++11 -fno-rtti -g")

set (INCLUDE_DIR "${CMAKE_INSTALL_INCLUDEDIR}/include/dg")
set (LIB_DIR "${CMAKE_INSTALL_LIBDIR}/lib/")
install(TARGETS LLVMdg
	LIBRARY DESTINATION ${LIB_DIR})

install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/ADT/DGContainer.h
	${CMAKE_SOURCE_DIR}/include/dg/ADT/Bitvector.h
	${CMAKE_SOURCE_DIR}/include/dg/ADT/Bits.h
	${CMAKE_SOURCE_DIR}/include/dg/ADT/NumberSet.h
	DESTINATION ${INCLUDE_DIR}/ADT/
)

install(FILES
        ${CMAKE_SOURCE_DIR}/include/dg/analysis/Offset.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/SubgraphNode.h
	DESTINATION ${INCLUDE_DIR}/analysis/
)
install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/Pointer.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/PointsToSet.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/MemoryObject.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/PointerSubgraph.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/PointerAnalysis.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/PointerAnalysisFI.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/PointerAnalysisFS.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/PointsTo/PointerSubgraphValidator.h
	DESTINATION ${INCLUDE_DIR}/analysis/PointsTo/
)

install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/analysis/ReachingDefinitions/ReachingDefinitions.h
	${CMAKE_SOURCE_DIR}/include/dg/analysis/ReachingDefinitions/RDMap.h
	DESTINATION ${INCLUDE_DIR}/analysis/ReachingDefinitions/
)

install(FILES
	${CMAKE_SOURCE_DIR}/lib/analysis/ReachingDefinitions/Srg/MarkerSRGBuilderFI.h
	${CMAKE_SOURCE_DIR}/lib/analysis/ReachingDefinitions/Srg/MarkerSRGBuilderFS.h
	DESTINATION ${INCLUDE_DIR}/analysis/ReachingDefinitions/Srg/
)

install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/PointsTo/PointerAnalysis.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/PointsTo/LLVMPointerAnalysisOptions.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/PointsTo/PointerSubgraph.h
	${CMAKE_SOURCE_DIR}/lib/llvm/analysis/PointsTo/PointerSubgraphValidator.h
	DESTINATION ${INCLUDE_DIR}/llvm/analysis/PointsTo/
)

install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/ReachingDefinitions/ReachingDefinitions.h
	${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ReachingDefinitions/LLVMRDBuilder.h
	${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ReachingDefinitions/LLVMRDBuilderSemisparse.h
	${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ReachingDefinitions/LLVMRDBuilderDense.h
	DESTINATION ${INCLUDE_DIR}/llvm/analysis/ReachingDefinitions/
)
install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/BBlock.h
	${CMAKE_SOURCE_DIR}/include/dg/Node.h
	${CMAKE_SOURCE_DIR}/include/dg/DependenceGraph.h
	DESTINATION ${INCLUDE_DIR}
)
install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/DefUse/DefUse.h
	DESTINATION ${INCLUDE_DIR}/llvm/analysis/DefUse/
)
install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/llvm/LLVMNode.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/LLVMDependenceGraph.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/LLVMDependenceGraphBuilder.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/LLVMSlicer.h
	${CMAKE_SOURCE_DIR}/lib/llvm/LLVMDGVerifier.h
	${CMAKE_SOURCE_DIR}/lib/llvm/llvm-utils.h
	DESTINATION ${INCLUDE_DIR}/llvm/
)

install(FILES
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/ThreadRegions/ControlFlowGraph.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/ThreadRegions/MayHappenInParallel.h
	${CMAKE_SOURCE_DIR}/include/dg/llvm/analysis/ThreadRegions/ThreadRegion.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/CallFuncPtrNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/CallNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/CallReturnNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/EntryNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/ExitNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/ForkNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/GeneralNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/JoinNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/LockNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/Node.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/NodeIterator.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/Nodes.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/ReturnNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Nodes/UnlockNode.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Graphs/BlockGraph.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Graphs/CriticalSectionsBuilder.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Graphs/FunctionGraph.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Graphs/GraphBuilder.h
        ${CMAKE_SOURCE_DIR}/lib/llvm/analysis/ThreadRegions/include/Graphs/ThreadRegionsBuilder.h
        DESTINATION ${INCLUDE_DIR}/llvm/analysis/ThreadRegions
)
