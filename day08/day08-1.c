#include<stdio.h>
int main()
{
	char str[100];
	char* swap=str;
	char temp;
	int i;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", str);
	for (i = 0; i < 50;i++) {
		*swap = str[i];
		temp = *swap;
		str[i] = str[100 - i];
		str[100 - i] = temp;
	}

	printf("%s", str);

	return 0;
}