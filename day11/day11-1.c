#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main()
{
	float a, b, c, d;
	printf("x^2�� ����� �Է����ּ��� : ");
	scanf_s("%f", &a);
	printf("x�� ����� �Է����ּ��� : ");
	scanf_s("%f", &b);
	printf("������� �Է����ּ��� : ");
	scanf_s("%f", &c);
	
	d = (pow(b, 2) - 4 * a * c);
	if (d < 0) {
		
	}else if (d == 0) {
		printf("�߱� : %.2f",(-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
	}else {
		printf("%.2f\n",(-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
		printf("%.2f",(-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
	}
	return 0;
}