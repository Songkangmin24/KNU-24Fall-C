#include<stdio.h>
int main()
{
	int num = 5;//피라미드의 줄수 지정
	int i, j;

	for (i = 0; i < num; i++) {
		for (j = num-i-1; j >0 ;j--) { //피라미드 왼쪽 공백 출력
			printf(" "); 
		}
		for (j = 1; j <= (i*2)+1; j++) { //피라미드 * 출력
			printf("*");
		}
		printf("\n");
	}


	return 0;
}