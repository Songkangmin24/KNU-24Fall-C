#include<stdio.h>
#include<stdlib.h>

#define SIZE 10 //2차원 배열의 크기 선언

void fillRandom(int array[SIZE][SIZE]) //array에 1~20까지 랜덤한 값을 집어넣음
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			array[i][j] = (rand() % 20) + 1;
		}
	}
	return;
}

void printArray(int array[SIZE][SIZE]) //array에 있는 값들을 출력함
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%02d ", array[i][j]);
		}
		printf("\n");
	}
	return;
}

void movePointer(void* array) // array[0][0]의 주소를 받아옴
{
	int x=0,y = 0; //좌표를 나타내기 위한 변수 추가
	int n;
	while (x<SIZE&&y<SIZE) { //좌표평면상에 있는 동안 반복되게 설정
		n = *(int*)array;
		printf("현재 위치: (%d, %d), 배열의 값 : %d\n", x,y,n); //좌표와 그 좌표에 있는 값을 출력
		(int*)array += n;
		x +=n;
		if (x >= SIZE) { //x와 y좌표 보정
			x -= SIZE;
			y++;
			if (x >= SIZE) { //최대로 20까지 더해지기때문에 한번 반복함
				x -= SIZE;
				y++;
			}
		}
	}
	y--,x = x+SIZE- n; //마지막 증감식에 대한 보정
	printf("더 이동할 수 없습니다.\n 종료 위치 : (%d, %d), 배열의 값 : %d",x,y,n);//마지막 위치 출력
	return;
}


int main()
{
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);

	return 0;
}