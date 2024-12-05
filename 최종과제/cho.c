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
//함수의 설정

//시작함수
//게임 방법 출력, 속도설정, 모드설정
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
//게임에 필요한 키 알려줌
void print_key(){
	printf("w : Up\na : Right\ns : Down\nd : Left\n");
	printf("q : quit\np : pause\n");
}



//게임 실행함수
// 게임 실행화면
// snake동작 . 게임모드에 따라 실행
// 게임오버의 판정 . 게임모드에 따라 실행
// 사과의 판별

//게임 실행화면 함수 //clean 게임 화면설정, 일시중시카운트, 점수, 현재 최고점

//snake 게임 동작. 일반. 입력제한
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

//리스트의 형식으로 각 몸통이 가진 x값을 기억함
//이동할때 하나씩 뒤로 움직이면 댐
struct snake snake_move(int mode,struct snake po,int le,배열의 리스트) {
	int i = 0;
	//누르고 있는 키의 값 입력받기
	for (le) { //리스트값 옮기기
		
	}
	if (mode == 1) {
		//po로 좌표이동
		printf("O");
		//pv리스트의 0번째 값부터 이동 출력
		for (i = 0; i <=le) {
			//move()
			printf("o");
		}
	}
	else if (mode == 2) {
		//좌표이동
	}
	else {
		//좌표이동
	}
	return po;
};

//snake 박스 판정
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

int die_check_snake(struct snake po,배열의 리스트,int le) {
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

//랭킹 등록함수
//랭킹여부 판별
// 사용자명 입력받음 
//리스트 등록
//리스트 삭제

//재시작여부 + 랭킹 출력

int main()
{
	struct set_value main_set;
	main_set = game_set();
	//게임 실행 함수
	game(main_set);
	//게임이 끝난후 랭킹 등록함수
	//재시작??

	return 0;
}