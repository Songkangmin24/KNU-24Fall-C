#include<stdio.h>

struct Product //product ����ü ����
{
	int ID;
	char name[100];
	int pr;
};

void printProduct(struct Product p) { //�Է¹��� product ����Լ�
	printf("\n��ǰ ID : %d",p.ID);
	printf("\n��ǰ�� : %s", p.name);
	printf("\n���� : %d��", p.pr);
	return;
}

int main() {
	int i;
	struct Product p[5];
	for (i = 0; i < 5; i++) { //5ȸ product �Է¹���
		printf("��ǰ�� ������ �Է��ϼ��� (�Է��ߴ��� id�� 0�Է�)\n");
		printf("��ǰ ID : ");
		scanf_s("%d", &p[i].ID);
		if (p[i].ID == 0) { //id=0�ϰ�� �Է��ߴ�
			break;
		}
		printf("��ǰ�� : ");
		scanf_s("%s", p[i].name,sizeof(p[i].name));
		printf("���� : ");
		scanf_s("%d", &p[i].pr);
		printf("\n");
	}

	printf("\n�Է��ߴ�\n\n<<�Է��� ��ǰ ���>>");

	for (i = 0; i < 5; i++) {
		if (p[i].ID == 0) { //id=0�ϰ�� ����ߴ�
			if (i == 0) {
				printf("\n�Էµ� ��ǰ�� �����ϴ�.");
			}
			break;
		}
		printProduct(p[i]);
		printf("\n");
	}

	return 0;
}