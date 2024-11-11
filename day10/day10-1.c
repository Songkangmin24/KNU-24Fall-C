#include<stdio.h>
#include<string.h>
head = NULL;
struct sc_st
{
	char name[100];
	int score;
};

struct NODE
{
	struct sc_st node;
	struct NODE* link;
};

struct NODE* create_node(struct sc_st a) 
{
	
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->node.name, a.name,sizeof(a.name));
	new_node->node.score = a.score;
	new_node->link = NULL;

	return new_node;
}
/*넣을 노드의 위치
struct NODE* where_node(struct sc_st value)
{
	struct NODE* cur = head;
	while (cur->link != NULL) {
		if (value.score > cur->node.score) {
			return cur;
		}
		cur = cur->link;
	}
	return cur;
}*/

//새로운 노드를 추가할때 이전과 이후 노드의 연결도 다시 해야함
void insert_node(struct sc_st value)
{
	struct NODE* new_node=(struct NODE*)malloc(sizeof(struct NODE));
	new_node->node.score = value.score;
	strcpy_s(new_node->node.name, value.name,sizeof(value.name));
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->node.score < value.score) {//현재 노드가 입력받은 노드보다 뒤로감
			new_node->link = cur;
			prev->link = new_node;
			return;
		}
		prev = cur;
		cur = cur->link;
	}
	cur->link = new_node;
	new_node->link = NULL;
	return;

}

//노드 출력
void print_nodes() { 
	struct NODE* cur = head->link;
	while (cur != NULL) {
		print("\n%s : %d점",cur->node.name,cur->node.score);
		cur = cur->link;
	}
}
/* 노드순회
struct NODE* find_node(struct sc_st value)
{
	struct NODE* cur = head -> link;
	while(cur != NULL) {
		if (cur->node.name == value.name) {
			return cur;
		}
		cur = cur->link;
	}
}*/

// 노드삭제
int delete_node(struct sc_st value)
{
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->node.name == value.name) {
			prev->link = cur ->link;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main()
{
	struct sc_st temp;
	temp.score = 50;
	strcpy_s(temp.name, "홍길동",sizeof("홍길동"));
	create_node(temp);
	int mode=0;
	while (1) {
		while (1) {//입력이 1,2,3일 때까지 입력받음
			printf("\n1.학생의 성적을 입력\n2.학생 정보 제거\n3.프로그램 종료");
			printf("\ninput : ");
			scanf_s("%d", &mode);
			if (mode == 1 || mode == 2 || mode == 3) {
				break;
			}
			else {
				printf("\n옳바르지 않은 입력입니다.");
			}
		}
		if (mode == 1) {
			printf("학생의 이름 : ");
			scanf_s("%s", temp.name, sizeof(temp.name));
			printf("%s의 성적", temp.name);
			scanf_s("%d", &temp.score);
			insert_node(temp);//노드추가
		}
		else if (mode == 2) {
			printf("정보를 제거하려는 학생의 이름 : ");
			scanf_s("%s", temp.name, sizeof(temp.name));
			delete_node(temp); //노드 삭제
		}
		else {
			break;
		}
		print_nodes();
	}
	printf("\n프로그램을 종료합니다.");
	return 0;
}


