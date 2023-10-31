/* divide.c */
#include <stdio.h>
#include <stdarg.h>

int divide(int a, int b)
{
	if ( b != 0){
		int c = a/b;
		return c;
	}
	else
		printf("0을 입력하셨습니다. 다시 입력해주세요");
}
