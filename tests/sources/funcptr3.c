#include <assert.h>

void set2(int *b)
{
	*b = 13;
}

void set(int *a)
{
	void (*f)(int *b);
	f = set2;
	f(a);
}

void (*s)(int *) = set;
int main(void)
{
	int a, b, c;
	a = b + c;
	b = 3;
	c = 5;
	s(&a);

	assert(a == 13);
	return 0;
}