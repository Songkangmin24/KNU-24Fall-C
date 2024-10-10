#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
	double x = 0;
	double y = 0;
	int count = 0, in_count = 0; //점의 위치를 찍는 횟수, 점이 부채꼴안에 들어간 횟수
	double sum = 0; //x와 y를 이용하여 구한 점과 부채꼴의 중심 사이의 거리
	double r = 1.0; //부채꼴의 반지름
	double pi; // 넓이 비 공식을 통해 구한 파이값
	int j;
	srand(time(NULL));

	for (int i = 1; i < 101; i++) {
		
		while (count < 10000000*i) {

			x = (double)rand() / (double)RAND_MAX;
			y = (double)rand() / (double)RAND_MAX; //점의 x와 y좌표 무작위로 배정
			x = pow(x, 2);
			y = pow(y, 2);
			sum = sqrt(x + y); //점과 부채꼴의 중심과의 거리
			if (sum < r) {
				in_count++; //점이 부채꼴에 들어가있을 경우 증가
			}
			count++;
		}
		pi = 4.0 * in_count / count;//파이값 구하기
		printf("%3d%%진행.. 원주율 : %f\t",i,pi);//진행도 표시
		for (j=0; j <20; j++) { //네모로 진행도 표시
			if (j<=(i-1)/5) {
				printf("■");
			}
			else {
				printf("□");
			}
		}
		printf("\n");
	}
	




	return 0;
}