/* my_assert_test.c */
#include <stdio.h>
#include <stdlib.h>

# define __ASSERT_VOID_CAST (void)
extern char *__progname;
extern void my_assert_fail (const char * assertion, const char *file, unsigned int line, const char *function)
{
		printf("%s:%s:%u:%s:Assertion '%s' failed.",__progname,file,line,function,assertion);
	
	        abort();		
}

#ifdef NDEBUG
	#define my_assert(expr)(__ASSERT_VOID_CAST(0))
#else
	#define my_assert(expr)((expr) ? __ASSERT_VOID_CAST(0) : my_assert_fail (#expr,__FILE__,__LINE__,__func__))
#endif


void foo(int num)
{
	my_assert(((num >= 0)&&(num <= 100)));
	
	printf("foo: num = %d\n", num);
}
		
int main(int argc, char *argv[])
{
	int num;
	
	if (argc < 2) {
	fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <=100)\n");
	exit(1);
	}
		num = atoi(argv[1]);
		foo(num);
}
