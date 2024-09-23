#include<stdio.h>
void swap(int* pa, int* pb);

int main()
{
	int a = 10, b = 20;
	printf("a=%d  b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d  b=%d", a, b);
	return 0;
}

void swap(int* pa, int* pb) {
	int temp = (*pa);
	*pa = *pb;
	*pb = temp;
	return;
}