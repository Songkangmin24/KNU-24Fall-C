#include<stdio.h>
int main()
{
	char aw;
	double a, b;
	printf("���ϴ� ����� �Է��Ͻÿ�.\n1.���ϱ� 2.���� 3.���ϱ� 4.������");
	printf("\n��� : ");
	scanf_s("%c", &aw);
	printf("\n���� 1�� �Է��ϼ��� : ");
	scanf_s("%lf", &a);
	while (1) {
		printf("\n���� 2�� �Է��ϼ��� : ");
		scanf_s("%lf", &b);
		if (aw == '4' && b == 0) {
			printf("0���� ���� �� �����ϴ�.");
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
		printf("�ùٸ� ���� �Էµ��� �ʾҽ��ϴ�.");
	}

}