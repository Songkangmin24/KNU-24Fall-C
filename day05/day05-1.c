#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n=0;
	int* std_num;
	char** name;
	int* score;
	int sum=0;
	int i = 0;
	printf("�л��� �ο��� �Է����ּ���. : ");
	scanf_s("%d", &n);

	std_num = (int*)malloc(sizeof(int) * n);
	name = (char**)malloc(sizeof(char*) * n);
	score= (int*)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++) {
		name[i] = (char*)malloc(sizeof(char) * 100);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("�й��� �Է����ּ��� : ");
		scanf_s("%d", &std_num[i]);
		printf("�̸��� �Է����ּ��� : ");
		scanf_s("%s", name[i],100);
		printf("������ �Է����ּ��� : ");
		scanf_s("%d", &score[i]);
		printf("\n");
	}
	
	for (i = 0; i < n; i++) {
		printf("%d. �й�:%d\t�̸�:%s\t����:%d\n", i + 1,std_num[i],name[i],score[i]);
	}
	for (i = 0; i < n; i++) {
		sum += score[i];
	}
	int max = score[0], min = score[0];
	for (i = 0; i < n; i++) {
		if (score[i] > max) {
			max = score[i];
		}
		if (score[i] < min) {
			min = score[i];
		}
	}
	printf("\n�л� �� : %d �հ� : %d ��� %d �ִ� : %d �ּ� : %d",n,sum,sum/n,max,min);

	free(std_num);
	std_num = NULL;
	free(score);
	score = NULL;
	for (i = 0; i < n; i++) {
		free(name[i]) ;
		name[i] = NULL;
	}
	
	
	return 0;
}