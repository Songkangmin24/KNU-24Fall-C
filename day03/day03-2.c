#include<stdio.h>
int p(int num);

int main() {
	int num;
	printf("����� ���丮�� �� �Է� : ");
	scanf_s("%d", &num);
	printf("%d! = %d", num, p(num));
	return 0;
}

int p(int num) {
	int res = 1;
	if (num == 0) {
		return 1;
	}
	res = num * p(num - 1);
	return res;
}