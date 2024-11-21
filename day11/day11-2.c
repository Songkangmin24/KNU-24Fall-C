#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main() 
{
	int st, end, n;
	double t,h,as=0;
	printf("적분을 시작 값을 입력하세요 : ");
	scanf_s("%d", &st);
	printf("적분을 끝낼 값을 입력하세요 : ");
	scanf_s("%d", &end);
	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%d", &n);

	for (long long i = 1; i <= n; i++) {
		int len = (pow(2, i));
		t = (end - st) / (double)(pow(2,i)); //2^n일때 구간의 크기
		as = 0;
		for (float j = 0; j < len; j++) { //나눈 간격만큼 이동
			double x_now = st + t * j;
			h = -log10(1/ x_now) + sin(x_now); //높이 구하기
			as=as+(t* h); //넓이 구하고 총 넓이에 더하기
		}
		printf("구간 \t %.0f 적분 결과 : %f\n",pow(2,i),as); //결과 출력
	}
	return 0;
}