#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include <io.h> 
#include <conio.h> 

int speed_max = 10;
int speed_min = 1;
int box_x = 40;
int box_y = 20;
int gameover = 0;
int pause = 0;
int score;
int OnGame = 1;

typedef struct list {
	int score;
	char name[3];
};

struct list rank_mode1[5];
struct list rank_mode2[5];
struct list rank_mode3[5];

typedef struct set_value {
	int speed;
	int mode;
};
//snake의 좌표를 기억할 동적리스트
typedef struct node
{
	int po;
	struct node* next;
};
struct node* head = NULL;

struct node* creat_node(int pos) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node*));
	newnode->po = pos;
	newnode->next = NULL;
	return newnode;
};

int find_tail_node(void) {
	struct node* mt = head;
	if (mt == NULL) {
		return;
	}
	struct node* cur = head->next;
	while (cur != NULL) {
		cur = cur->next;
	}
	return cur->po;
};

int find_num_node(int po) {
	struct node* mt = head;
	if (mt == NULL) {
		return 0;
	}
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
	if (prev == NULL) {
		return;
	}
	struct node* cur = head->next;
	while (cur != NULL) {
		prev->next = cur->next;
		free(cur);
	}
	return;
};

void node_move(int po) {
	struct node* prev = head;
	if (prev == NULL) {
		return;
	}
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

void print_key(void);
struct set_value game_set(void) {
	struct set_value set;
	set.mode = 0;
	set.speed = speed_max + 1;
	while (set.speed > speed_max || set.speed < speed_min) {
		system("cls");
		print_key();
		printf("\nSet speed (1~10) : ");
		scanf_s("%d", &set.speed, sizeof(set.speed));
	}
	system("cls");
	while (set.mode > 3 || set.mode < 1) {
		system("cls");
		print_key();
		printf("speed : %d\n", set.speed);
		printf("Set mode (1,2,3)\n");
		printf("1 : normel\n2 : hard\n3 : pass box\n");
		scanf_s("%d", &set.mode, sizeof(set.mode));
	}
	system("cls");
	return set;
}
//게임에 필요한 키 알려줌
void print_key(void) {
	printf("w : Up\na : Right\ns : Down\nd : Left\n");
	printf("q : quit\np : pause\n");
}

void print_screen(int apple_po, int snake_po);
void die_check(int mode, int po);
int apple_pos(void);
int snake_move(int key, int snake_po);
int input(int key);

//함수의 설정

//게임 실행함수
// 게임 실행화면 0
// snake동작 . 게임모드에 따라 실행 0
// 게임오버의 판정 . 게임모드에 따라 실행 1
// 사과의 판별 1
//게임 실행화면 함수 //clean 게임 화면설정, 일시중시카운트, 점수, 현재 최고점
//snake 게임 동작. 일반. 입력제한
int game(struct set_value game_set) {
	int key = 0;
	int snake_po = (box_x * box_y) / 2;
	int apple_po = apple_pos();
	int speed = game_set.speed;
	int mode = game_set.mode;
	int die = 0;
	score = 0;
	creat_node((box_x * box_y));
	while (die == 0) {
		Sleep(800);
		key = input(key);
		if (pause == 0) {
			system("cls");
			snake_po = snake_move(key, snake_po);
			node_move(snake_po);
			if (find_num_node(apple_po) == 1) {
				score++;
				apple_po = apple_pos();
				creat_node(find_tail_node());
			}
			die_check(mode, snake_po);
			print_screen(apple_po,snake_po);
		}
	}
};
//사과 위치 설정
int apple_pos(void) {
	int apple_po = rand() % (box_x * box_y);
	int pass = 0;
	while (pass == 0) {
		apple_po = rand() % (box_x * box_y);
		if ((apple_po % box_x == 0 || apple_po % box_x == box_x - 1) && apple_po < box_x || apple_po>(box_x * box_y) - box_x) {

		}else if (find_num_node(apple_po) == 0) {
			pass = 1;
		}
	}
	return apple_po;
};

//리스트의 형식으로 각 몸통이 가진 x값을 기억함
//이동할때 하나씩 뒤로 움직이면 댐
int snake_move(int key, int snake_po) {
	int po = 0;
	switch (key) {
	case 1://a
		po = snake_po - 1;
		break;
	case 2://s
		po = snake_po + box_x;
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

void print_screen(int apple_po,int snake_po) {
	int i = 0;
	int j = 0;
	for (i = 0; i < box_x * box_y; i++) {
		if (i < box_x||i>(box_x*box_y)-box_x) {
			printf("-");
		}
		else if (i % box_x == 0 || i % box_x == box_x - 1) {
			printf("|");
			if (i % box_x == box_x - 1) {
				printf("\n");
			}
		}
		else if (i == apple_po) {
			printf("#");
		}
		else if (find_num_node(i) == 1) {
			if (snake_po == i) {
				printf("@");
			}
			else {
				printf("o");
			}
		}
		else {
			printf(" ");
		}
		if (i == box_x-1) {
			printf("\n");
		}
	}
}

//죽음 판정
void die_check(int mode, int po) {
	int die = 0;
	int i, pass = 0;
	die = find_num_node(po);//몸통에 대한 판정
	if (mode == 1 || 2) {//박스에 대한 판정
		for (i = 0; i < box_x; i++) { //윗부분
			die = find_num_node(i);
		}
		for (i = 0; i < box_x * box_y;) { //좌우벽
			die = find_num_node(i);
			i = i + box_x - 1;
			die = find_num_node(i);
			i++;
		}
		for (i = box_x * (box_y - 1); i < box_x * box_y; i++) { //아랫부분
			die = find_num_node(i);
		}
	}
	else {
		for (i = 0; i < box_x; i++) {
			if (po == i) {
				po = po + (box_x * (box_y - 1));
				pass = 1;
				break;
			}
		}if (pass == 0) {
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
		case'p':
		case'P':
			if (pause == 0) {
				pause = 1;
			}
			else {
				pause == 0;
			}
			break;
		}
		
	}
};

//랭킹 등록함수
//랭킹여부 판별
// 사용자명 입력받음 
//리스트 등록
//리스트 삭제

/*void rank(int mode) {
	int i = 0;
	int temp_score;
	char temp_name;
	char name;
	if (mode == 1) {
		while (rank_mode1[i].score != NULL) {
			if (rank_mode1[i].score < score) {
				temp_score = rank_mode1[i].score;
				strcpy(&temp_name, rank_mode1[i].name);
				printf("input your name : ");
				scanf_s("%s", &name, sizeof(name));
				rank_mode1[i].score = score;
				strcpy(rank_mode1[i].name, &name);
				i++;
				if (i == 5) {
					break;
				}
				rank_mode1[i].score=temp_score;
				strcpy(rank_mode1[i].name,&temp_name);
			}
			i++;
			if (i == 5) {
				break;
			}
		}
	}else if (mode == 2) {
		while (rank_mode2[i].score != NULL) {
			if (rank_mode2[i].score < score) {
				temp_score = rank_mode2[i].score;
				strcpy(&temp_name, rank_mode2[i].name);
				printf("input your name : ");
				scanf_s("%s", &name, sizeof(name));
				rank_mode2[i].score = score;
				strcpy(rank_mode2[i].name, &name);
				i++;
				if (i == 5) {
					break;
				}
				rank_mode2[i].score = temp_score;
				strcpy(rank_mode2[i].name, &temp_name);
			}
			i++;
			if (i == 5) {
				break;
			}
		}
	}else if (mode == 3) {
		while (rank_mode3[i].score != NULL) {
			if (rank_mode3[i].score < score) {
				temp_score = rank_mode3[i].score;
				strcpy(&temp_name, rank_mode3[i].name);
				printf("input your name : ");
				scanf_s("%s", &name, sizeof(name));
				rank_mode3[i].score = score;
				strcpy(rank_mode3[i].name, &name);
				i++;
				if (i == 5) {
					break;
				}
				rank_mode3[i].score = temp_score;
				strcpy(rank_mode3[i].name, &temp_name);
			}
			i++;
			if (i == 5) {
				break;
			}
		}
	}
	return;
	
};*/

//재시작여부 + 랭킹 출력
void re_start(void) {
	system("cls");
	int i = 0;
	int aw;
	printf("Mode1 Rank\n");
	for (i; i < 5; i++) {
		printf("%s\t- %d\n",rank_mode1[i].name, rank_mode1[i].score);
	}
	i = 0;
	printf("\nMode2 Rank\n");
	for (i; i < 5; i++) {
		printf("%s\t- %d\n", rank_mode2[i].name, rank_mode2[i].score);
	}
	i = 0;
	printf("\nMode3 Rank\n");
	for (i; i < 5; i++) {
		printf("%s\t- %d\n", rank_mode3[i].name, rank_mode3[i].score);
	}
	printf("\n start new game? (yes=1)\n");
	scanf_s("%d", &aw);
	if (aw != 1) {
		OnGame = 0;
	}
	return;
}


int main()
{
	srand(time(NULL));
	struct set_value main_set;
	while (OnGame == 1) {
		main_set = game_set();
		system("cls");
		//게임 실행 함수
		game(main_set);
		//게임이 끝난후 랭킹 등록함수
		//rank(main_set.mode);
		re_start();
	}
	system("cls");
	printf("thank you for playing");
	return 0;
}