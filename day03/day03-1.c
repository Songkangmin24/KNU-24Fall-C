#include<stdio.h>

int prime(int a);

int main() {
	int num;
	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);
	if (prime(num) == 1) {
		printf("�ش� ���� �Ҽ��Դϴ�.");
	}
	else {
		printf("�ش� ���� �Ҽ��� �ƴմϴ�.");
	}
}

int prime(int number) {
	for ( int i=2; i < number; i++) {
		printf("ó�� %dȸ\n", i-1);
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}