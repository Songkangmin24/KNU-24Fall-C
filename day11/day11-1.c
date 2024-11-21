#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main()
{
	float a, b, c, d;
	printf("x^2의 계수를 입력해주세요 : ");
	scanf_s("%f", &a);
	printf("x의 계수를 입력해주세요 : ");
	scanf_s("%f", &b);
	printf("상수항을 입력해주세요 : ");
	scanf_s("%f", &c);
	
	d = (pow(b, 2) - 4 * a * c);
	if (d < 0) {
		
	}else if (d == 0) {
		printf("중근 : %.2f",(-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
	}else {
		printf("%.2f\n",(-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
		printf("%.2f",(-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
	}
	return 0;
}