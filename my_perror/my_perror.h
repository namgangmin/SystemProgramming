/* my_perror() */
#include <stdio.h>
#include <string.h>
#include <errno.h>
extern int errno;

void my_perror(char *s){

	if (s != NULL)
		strcat(s, " : ");
	
	else
		s = "";
	switch(errno){
	case 2:
		printf("%s No such file or directory",s);
		break;
	case 9: 
		printf("%s Bad file number",s);
		break;
	case 22:
		printf("%s Invalid argument",s);
		break;
	case 34:
		printf("%s Math result not Representable",s);
		break;
	case 62:
		printf("%s Timer expired",s);
		break;
	}
}	
