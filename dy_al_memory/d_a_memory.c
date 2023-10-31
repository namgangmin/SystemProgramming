/* d_a_memory */
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b,c,d,e,f;
	printf("행의 크기 입력 : ");
	scanf("%d", &a);
	printf("열의  크기 입력 : ");
	scanf("%d", &b); 

	int** mx1_ptr = (int **)malloc(a * sizeof(int*));
	int** mx2_ptr = (int **)malloc(a * sizeof(int*));
	int** mx_sum_ptr = (int **)malloc(a * sizeof(int*));
	for (int i = 0; i < a; i++){
		mx1_ptr[i] = (int *)malloc(b * sizeof(int));
		mx2_ptr[i] = (int *)malloc(b * sizeof(int));
		mx_sum_ptr[i] = (int *)malloc(b * sizeof(int));
	}
	if(mx1_ptr == NULL || mx2_ptr == NULL || mx_sum_ptr == NULL) {
	                printf("메모리 할당 실패");
           	        exit(-1);
	}
	printf("첫번째 행렬 수 입력 \n");
	for(int i=0; i< a; i++){
		for(int j = 0; j<b; j++){
			scanf("%d", &mx1_ptr[i][j]);
		}
	}
	printf("두번째 행렬 수 입력 \n");
	for (int i=0; i< a; i++){
		for (int j = 0; j<b; j++){
			scanf("%d", &mx2_ptr[i][j]);
		}
	}
	for (int i = 0; i < a; i++){
		for (int j = 0; j <b; j++){
			mx_sum_ptr[i][j] = mx1_ptr[i][j] + mx2_ptr[i][j];
		}
	}
	
	for (int i = 0; i < a; i++){
		printf("\n");
		for (int j = 0; j <b; j++){
			printf("%d ",mx_sum_ptr[i][j]);
		}
	}
	printf("\n");
	for (int i =0; i<a; i++){
	       free(mx1_ptr[i]);
       	       free(mx2_ptr[i]);
	       free(mx_sum_ptr[i]);
	}	       
	free (mx1_ptr);
	free (mx2_ptr);
	free (mx_sum_ptr);

}
