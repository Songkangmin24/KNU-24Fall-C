#include<stdio.h>
int main()
{
	int num = 5;//�Ƕ�̵��� �ټ� ����
	int i, j;

	for (i = 0; i < num; i++) {
		for (j = num-i-1; j >0 ;j--) { //�Ƕ�̵� ���� ���� ���
			printf(" "); 
		}
		for (j = 1; j <= (i*2)+1; j++) { //�Ƕ�̵� * ���
			printf("*");
		}
		printf("\n");
	}


	return 0;
}