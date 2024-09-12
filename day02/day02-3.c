#include<stdio.h>
int main()
{
	int i;
	for (i = 0; i <= 99; i++) {
		if (i % 3 == 0 && i % 4 == 0) {
			printf("%2d\n", i);
		}
		else if (i % 7 == 0) {
			printf("%2d\n", i);
		}
	}
	return 0;
}