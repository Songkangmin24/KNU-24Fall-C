#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include <io.h> 
#include <conio.h> 

int speed_max = 10;
int speed_min = 1;
int box_x = 20;
int box_y = 20;
int mode;
int gameover=0;

typedef struct set_value {
	int speed;
	int mode;
};
//snake�� ��ǥ�� ����� ��������Ʈ
typedef struct node
{
	int po;
	struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;

struct node* creat_node(int po) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node*));
	newnode->po = po;
	newnode->next = NULL;
	return newnode;
};

int find_tail_node(void) {
	struct node* cur = head->next;
	while (cur != NULL) {
		cur = cur->next;
	}
	return cur->po;
};

int find_num_node(int po) {
	struct node* cur = head->next;
	while (cur != NULL) {
		if (cur->po == po) {
			return 1;
		}
		cur = cur->next;
	}
	return 0;
};

void clear_node(void) {
	struct node* prev = head;
	struct node* cur = head->next;
	while (cur != NULL) {
		prev->next = cur->next;
		free(cur);
	}
	return;
};

void node_move(int po) {
	struct node* prev = head;
	if (prev->next != NULL) {
		struct node* cur = head->next;
		cur->po = po;
		while (cur->next != NULL) {
			prev = prev->next;
			cur = cur->next;
			cur->po = prev->po;
		}
	}
	return;
};
void print_screen(int apple_po);
void die_check(int mode, int po);
int apple_pos(void);
int snake_move(int key, int snake_po);
int input(int key);

//�Լ��� ����

//���� �����Լ�
// ���� ����ȭ�� 0
// snake���� . ���Ӹ�忡 ���� ���� 0
// ���ӿ����� ���� . ���Ӹ�忡 ���� ���� 1
// ����� �Ǻ� 1
//���� ����ȭ�� �Լ� //clean ���� ȭ�鼳��, �Ͻ��߽�ī��Ʈ, ����, ���� �ְ���
//snake ���� ����. �Ϲ�. �Է�����
int game(struct set_value game_set) {
	int key = 0;
	int snake_po = (box_x * box_y)/2;
	int apple_po = apple_pos();
	int speed = game_set.speed;
	int mode = game_set.mode;
	int die = 0, score = 0, len = 3;
	creat_node((box_x * box_y) / 2 + 1);
	creat_node((box_x * box_y) / 2 + 2);
	while (die == 0) {
		Sleep(700);
		system("cls");
		key = input(key);
		snake_po=snake_move(key,snake_po);
		node_move(snake_po);
		if (find_num_node(apple_po) == 1) {
			score++;
			len++;
			apple_po=apple_pos();
			creat_node(find_tail_node());
		}
		die_check(mode, snake_po);
		print_screen(apple_po);
	}
};
//��� ��ġ ����
int apple_pos(void) {
	int apple_po = rand() % (box_x * box_y);
	int pass = 0;
	while (pass = 0) {
		apple_po = rand() % (box_x * box_y);
		if (find_num_node(apple_po) == 0) {
			pass = 1;
		}
	}
	return apple_po;
};

//����Ʈ�� �������� �� ������ ���� x���� �����
//�̵��Ҷ� �ϳ��� �ڷ� �����̸� ��
int snake_move(int key,int snake_po) {
	int po=0;
	switch (key) {
	case 1://a
		po = snake_po-1;
		break;
	case 2://s
		po = snake_po +box_x;
		break;
	case 3://d
		po = snake_po + 1;
		break;
	case 4://w
		po = snake_po - box_y;
		break;
	default:
		break;
	}
	return po;

};

void print_screen(int apple_po) {
	int i = 0;
	int j = 0;
	for (i = 0; i < box_x * box_y; i++) {
		if (i < box_x) {
			printf("-");
		}else if (i % box_x == 0 || i % box_x == box_x - 1) {
			printf("|");
		}else if (i == apple_po) {
			printf("#");
		}else if (find_num_node(i) == 1) {
			struct node* cur = head->next;
			if (head->po == i) {
				printf("@");
			}else {
				printf("o");
			}
		}else {
			printf(" ");
		}
		
	}
}

//���� ����
void die_check(int mode, int po) {
	int die=0;
	int i, pass=0;
	die=find_num_node(po);//���뿡 ���� ����
	if (mode == 1 || 2) {//�ڽ��� ���� ����
		for (i = 0; i < box_x;i++) { //���κ�
			die=find_num_node(i);
		}
		for (i = 0; i < box_x * box_y;) { //�¿캮
			die = find_num_node(i);
			i = i + box_x-1;
			die = find_num_node(i);
			i++;
		}
		for (i = box_x*(box_y-1); i < box_x*box_y; i++) { //�Ʒ��κ�
			die = find_num_node(i);
		}
	}
	else {
		for (i = 0; i < box_x; i++) {
			if (po == i) {
				po = po+(box_x * (box_y - 1));
				pass = 1;
				break;
			}
		}if (pass = 0) {
			for (i = 0; i < box_x * box_y;) {
				if (po == i) {
					po = po + box_x - 1;
					pass = 1;
					break;
				}
				i = i + box_x - 1;
				if (po == i) {
					po = po - box_x + 1;
					pass = 1;
					break;
				}
				i++;
			}
		}
		if (pass == 0) {
			for (i = box_x * (box_y - 1); i < box_x * box_y; i++) {
				if (po == i) {
					po = po - (box_x * (box_y - 1));
					break;
				}
			}
		}
		
		
	}
	if (die == 1) {
		gameover = 1;
	}
};

int input(int key) {
	int key_put;
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
		case 'A':
			key_put = 1;
			break;
		case 's':
		case 'S':
			key_put = 2;
			break;
		case 'd':
		case 'D':
			key_put = 3;
			break;
		case 'w':
		case 'W':
			key_put = 4;
			break;
		case 'x':
		case 'X':
			gameover = 1;
			break;
		}
	}
};

//��ŷ ����Լ�
//��ŷ���� �Ǻ�
// ����ڸ� �Է¹��� 
//����Ʈ ���
//����Ʈ ����

//����ۿ��� + ��ŷ ���

int main()
{
	srand(time(NULL));
	struct set_value main_set;
	main_set.mode = 1;
	main_set.speed = 5;
	//���� ���� �Լ�
	game(main_set);
	//������ ������ ��ŷ ����Լ�
	//�����??

	return 0;
}