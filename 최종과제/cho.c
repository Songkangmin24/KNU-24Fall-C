#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

int speed_max = 10;
int speed_min = 1;
int box_x = 20;
int box_y = 20;

typedef struct set_value {
	int speed;
	int mode;
};

typedef struct snake {
	int x;
	int y;
};
//�Լ��� ����

//�����Լ�
//���� ��� ���, �ӵ�����, ��弳��
struct set_value game_set(void) {
	struct set_value set;
	
	while (set.speed > speed_max || set.speed < speed_min) {
		system("cls");
		print_key;
		printf("\nSet speed (1~10) : ");
		scanf_s("%d", set.speed);
	}
	system("cls");
	while (set.mode>3||set.mode<1) {
		system("cls");
		print_key;
		printf("speed : %d\n", set.speed);
		printf("Set mode (1,2,3)\n");
		printf("1 : normel\n2 : hard\n3 : pass box\n");
		scanf_s("%d", set.mode);
	}
	return set;
}
//���ӿ� �ʿ��� Ű �˷���
void print_key(){
	printf("w : Up\na : Right\ns : Down\nd : Left\n");
	printf("q : quit\np : pause\n");
}



//���� �����Լ�
// ���� ����ȭ��
// snake���� . ���Ӹ�忡 ���� ����
// ���ӿ����� ���� . ���Ӹ�忡 ���� ����
// ����� �Ǻ�

//���� ����ȭ�� �Լ� //clean ���� ȭ�鼳��, �Ͻ��߽�ī��Ʈ, ����, ���� �ְ���

//snake ���� ����. �Ϲ�. �Է�����
int game(struct set_value game_set) {
	struct snake p;
	p.x = box_x / 2;
	p.y = box_y / 2;
	int speed = game_set.speed;
	int mode = game_set.mode;
	int die = 0, score = 0, len = 3;
	struct apple 
	apple_po = set_apple_po();
	while (die == 0) {
		system("cls");
		print_box();
		snake_move(mode,p,score);
		die = die_check_box(mode,p);
		die = die_check_snake(p, list, len);

	}
};

void print_box(void) {
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
			printf(" ");
		}
		printf("|\n");
	}
	printf("  ");
	for (i = 0; i < box_x; i++) {
		printf("-");
	}
}

//����Ʈ�� �������� �� ������ ���� x���� �����
//�̵��Ҷ� �ϳ��� �ڷ� �����̸� ��
struct snake snake_move(int mode,struct snake po,int le,�迭�� ����Ʈ) {
	int i = 0;
	//������ �ִ� Ű�� �� �Է¹ޱ�
	for (le) { //����Ʈ�� �ű��
		
	}
	if (mode == 1) {
		//po�� ��ǥ�̵�
		printf("O");
		//pv����Ʈ�� 0��° ������ �̵� ���
		for (i = 0; i <=le) {
			//move()
			printf("o");
		}
	}
	else if (mode == 2) {
		//��ǥ�̵�
	}
	else {
		//��ǥ�̵�
	}
	return po;
};

//snake �ڽ� ����
int die_check_box(int mode, struct snake po) {
	if (mode == 1 || 2) {
		if (po.x<0 || po.x>box_x) {
			return 1;
		}
		if (po.y<0 || po.y>box_y) {
			return 1;
		}
	}
	else {
		if (po.x<0) {
			po.x = box_x;
		}
		if (po.x > box_x) {
			po.x = 0;
		}
		if (po.y<0) {
			po.y=box_y;
		}if (po.x > box_y) {
			po.y = 0;
		}
	}
};

int die_check_snake(struct snake po,�迭�� ����Ʈ,int le) {
	int i;
	int j;
	for (i = 0; i <= le; i++) {
		for (j = 0; j <= i; j++) {
			if (list[i] = list[j]) {
				return 1;
			}
		}
	}
	return 0;
};

//��ŷ ����Լ�
//��ŷ���� �Ǻ�
// ����ڸ� �Է¹��� 
//����Ʈ ���
//����Ʈ ����

//����ۿ��� + ��ŷ ���

int main()
{
	struct set_value main_set;
	main_set = game_set();
	//���� ���� �Լ�
	game(main_set);
	//������ ������ ��ŷ ����Լ�
	//�����??

	return 0;
}