#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main() 
{
	int st, end, n;
	double t,h,as=0;
	printf("������ ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &st);
	printf("������ ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &end);
	printf("������ �ִ� ������ �Է��ϼ���(2^n) : ");
	scanf_s("%d", &n);

	for (long long i = 1; i <= n; i++) {
		int len = (pow(2, i));
		t = (end - st) / (double)(pow(2,i)); //2^n�϶� ������ ũ��
		as = 0;
		for (float j = 0; j < len; j++) { //���� ���ݸ�ŭ �̵�
			double x_now = st + t * j;
			h = -log10(1/ x_now) + sin(x_now); //���� ���ϱ�
			as=as+(t* h); //���� ���ϰ� �� ���̿� ���ϱ�
		}
		printf("���� \t %.0f ���� ��� : %f\n",pow(2,i),as); //��� ���
	}
	return 0;
}