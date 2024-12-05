#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

box_x = 40;
box_y = 20;

int main()
{
	int i = 0;
	int j = 0;
	printf("  ");
	for (i = 0; i < box_x; i++) {
		printf("-");
	}
	printf("\n");
	for (i = 0; i < box_y; i++) {
		printf("|");
		for (j = 0; j <= box_x; j++) {
			printf("o");
		}
		printf("|\n");
	}
	printf("  ");
	for (i = 0; i < box_x; i++) {
		printf("-");
	}
}