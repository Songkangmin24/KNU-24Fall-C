#include<stdio.h>
int main()
{
	char aw;
	double a, b;
	printf("원하는 기능을 입력하시오.\n1.더하기 2.빼기 3.곱하기 4.나누기");
	printf("\n기능 : ");
	scanf_s("%c", &aw);
	printf("\n숫자 1을 입력하세요 : ");
	scanf_s("%lf", &a);
	while (1) {
		printf("\n숫자 2을 입력하세요 : ");
		scanf_s("%lf", &b);
		if (aw == '4' && b == 0) {
			printf("0으로 나눌 수 없습니다.");
		}
		else {
			break;
		}
	}
	if (aw == '1') {
		printf("\n%lf + %lf = %lf ", a, b, a + b);
	}
	else if (aw == '2') {
		printf("\n%lf - %lf = %lf ", a, b, a - b);
	}
	else if (aw == '3') {
		printf("\n%lf * %lf = %lf ", a, b, a * b);
	}
	else if (aw == '4') {
		printf("\n%lf / %lf = %lf ", a, b, a / b);
	}
	else {
		printf("올바른 값이 입력되지 않았습니다.");
	}

}