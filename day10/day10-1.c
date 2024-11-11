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
/*���� ����� ��ġ
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

//���ο� ��带 �߰��Ҷ� ������ ���� ����� ���ᵵ �ٽ� �ؾ���
void insert_node(struct sc_st value)
{
	struct NODE* new_node=(struct NODE*)malloc(sizeof(struct NODE));
	new_node->node.score = value.score;
	strcpy_s(new_node->node.name, value.name,sizeof(value.name));
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	while (cur != NULL) {
		if (cur->node.score < value.score) {//���� ��尡 �Է¹��� ��庸�� �ڷΰ�
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

//��� ���
void print_nodes() { 
	struct NODE* cur = head->link;
	while (cur != NULL) {
		print("\n%s : %d��",cur->node.name,cur->node.score);
		cur = cur->link;
	}
}
/* ����ȸ
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

// ������
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
	strcpy_s(temp.name, "ȫ�浿",sizeof("ȫ�浿"));
	create_node(temp);
	int mode=0;
	while (1) {
		while (1) {//�Է��� 1,2,3�� ������ �Է¹���
			printf("\n1.�л��� ������ �Է�\n2.�л� ���� ����\n3.���α׷� ����");
			printf("\ninput : ");
			scanf_s("%d", &mode);
			if (mode == 1 || mode == 2 || mode == 3) {
				break;
			}
			else {
				printf("\n�ǹٸ��� ���� �Է��Դϴ�.");
			}
		}
		if (mode == 1) {
			printf("�л��� �̸� : ");
			scanf_s("%s", temp.name, sizeof(temp.name));
			printf("%s�� ����", temp.name);
			scanf_s("%d", &temp.score);
			insert_node(temp);//����߰�
		}
		else if (mode == 2) {
			printf("������ �����Ϸ��� �л��� �̸� : ");
			scanf_s("%s", temp.name, sizeof(temp.name));
			delete_node(temp); //��� ����
		}
		else {
			break;
		}
		print_nodes();
	}
	printf("\n���α׷��� �����մϴ�.");
	return 0;
}


