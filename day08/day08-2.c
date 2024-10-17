#include<stdio.h>
#include<stdlib.h>

#define SIZE 10 //2���� �迭�� ũ�� ����

void fillRandom(int array[SIZE][SIZE]) //array�� 1~20���� ������ ���� �������
{
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			array[i][j] = (rand() % 20) + 1;
		}
	}
	return;
}

void printArray(int array[SIZE][SIZE]) //array�� �ִ� ������ �����
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%02d ", array[i][j]);
		}
		printf("\n");
	}
	return;
}

void movePointer(void* array) // array[0][0]�� �ּҸ� �޾ƿ�
{
	int x=0,y = 0; //��ǥ�� ��Ÿ���� ���� ���� �߰�
	int n;
	while (x<SIZE&&y<SIZE) { //��ǥ���� �ִ� ���� �ݺ��ǰ� ����
		n = *(int*)array;
		printf("���� ��ġ: (%d, %d), �迭�� �� : %d\n", x,y,n); //��ǥ�� �� ��ǥ�� �ִ� ���� ���
		(int*)array += n;
		x +=n;
		if (x >= SIZE) { //x�� y��ǥ ����
			x -= SIZE;
			y++;
			if (x >= SIZE) { //�ִ�� 20���� �������⶧���� �ѹ� �ݺ���
				x -= SIZE;
				y++;
			}
		}
	}
	y--,x = x+SIZE- n; //������ �����Ŀ� ���� ����
	printf("�� �̵��� �� �����ϴ�.\n ���� ��ġ : (%d, %d), �迭�� �� : %d",x,y,n);//������ ��ġ ���
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