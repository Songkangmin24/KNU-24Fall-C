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
	printf("학생의 인원을 입력해주세요. : ");
	scanf_s("%d", &n);

	std_num = (int*)malloc(sizeof(int) * n);
	name = (char**)malloc(sizeof(char*) * n);
	score= (int*)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++) {
		name[i] = (char*)malloc(sizeof(char) * 100);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("학번을 입력해주세요 : ");
		scanf_s("%d", &std_num[i]);
		printf("이름을 입력해주세요 : ");
		scanf_s("%s", name[i],100);
		printf("점수를 입력해주세요 : ");
		scanf_s("%d", &score[i]);
		printf("\n");
	}
	
	for (i = 0; i < n; i++) {
		printf("%d. 학번:%d\t이름:%s\t점수:%d\n", i + 1,std_num[i],name[i],score[i]);
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
	printf("\n학생 수 : %d 합계 : %d 평균 %d 최대 : %d 최소 : %d",n,sum,sum/n,max,min);

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