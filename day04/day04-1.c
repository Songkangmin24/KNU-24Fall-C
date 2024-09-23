#include<stdio.h>
int main()
{
	int num1 = 100, num2 = 100;
	int* ptr;
	
	ptr= &num1;
	(*ptr) += 30;
	ptr = &num2;
	(*ptr) -= 30;
	
	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);
	return 0;
}