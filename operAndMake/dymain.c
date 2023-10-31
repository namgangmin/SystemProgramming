/* dymain.c */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	void *handle;
	int (*add)(int, int), (*sub)(int, int), (*multiply)(int, int), (*divide)(int, int);
	char *error;

	handle = dlopen("./report_2/libtest.so", RTLD_LAZY);
	if (!handle){
		fputs (dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s",error);
		exit(1);
	}
	sub = dlsym(handle, "sub");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s",error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s",error);
		exit(1);
	}	
	divide = dlsym(handle, "divide");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s",error);
		exit(1);
	}
	printf("add(3,7) = %d\n", (*add)(3,7));
	printf("sub(10,6) = %d\n", (*sub)(10,6));
	printf("multiply(9,3) = %d\n", (*multiply)(9,3));
	printf("divide(21,7) = %d\n", (*divide)(21,7));
	dlclose(handle);
}
