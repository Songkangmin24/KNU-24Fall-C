#include<stdio.h>

int prime(int a);

int main() {
	int num;
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);
	if (prime(num) == 1) {
		printf("해당 수는 소수입니다.");
	}
	else {
		printf("해당 수는 소수가 아닙니다.");
	}
}

int prime(int number) {
	for ( int i=2; i < number; i++) {
		printf("처리 %d회\n", i-1);
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}