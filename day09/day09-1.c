#include<stdio.h>

int x, y, z; 
struct vector //���� ����
{
	int x, y, z;
};

void add(struct vector p1, struct vector p2) { //������ �� �Լ�
	x = p1.x + p2.x;
	y = p1.y + p2.y;
	z = p1.z + p2.z;
	return;
}
void sub(struct vector p1, struct vector p2) { //������ �� �Լ�
	x = p1.x - p2.x;
	y = p1.y - p2.y;
	z = p1.z - p2.z;
	return;
}
int in_s(struct vector p1, struct vector p2) { //������ ���� �Լ�
	int sum;
	sum = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	return sum;
}
void out_s(struct vector p1, struct vector p2) { //������ ���� �Լ�
	x = p1.y * p2.z - p1.z * p2.y;
	y = p1.z * p2.x - p1.x * p2.z;
	z = p1.x * p2.y - p1.y * p2.x;
	return;
}

void print_vector(struct vector p) { //�Է¹��� ���͸� ����ϴ� �Լ�
	printf("vector (%d,%d,%d)\n",p.x,p.y,p.z);
}


int main() {
	int aw,sum;
	struct vector p[2]; //������ ���� 2�� ����
	
	printf("vector1 x : "); //���� 1 �Է�
	scanf_s("%d", &p[0].x);
	printf("vector1 y : ");
	scanf_s("%d", &p[0].y);
	printf("vector1 z : ");
	scanf_s("%d", &p[0].z);

	printf("\n");

	printf("vector2 x : "); //���� 2 �Է�
	scanf_s("%d", &p[1].x);
	printf("vector2 y : ");
	scanf_s("%d", &p[1].y);
	printf("vector2 z : ");
	scanf_s("%d", &p[1].z);


	printf("\n");
	print_vector(p[0]); //�Է¹��� ���� ���
	print_vector(p[1]);

	printf("1.������ ��\n2.������ ��\n3.������ ����\n4.������ ����\n5.����\n"); //����� ���� ���
	printf("����Է� : ");
	scanf_s("%d",&aw);
	
	if (aw == 1) { //����ڰ� �Է��� ���� ���� ��� ����
		add(p[0], p[1]);
		printf("������ ���� (%d, %d, %d)",x,y,z );
	}else if (aw == 2) {
		sub(p[0], p[1]);
		printf("������ ���� (%d, %d, %d)", x, y, z);
	}
	else if (aw == 3) {
		sum=in_s(p[0], p[1]);
		printf("������ ������ %d", sum);
	}
	else if (aw == 4) {
		out_s(p[0], p[1]);
		printf("������ ������ (%d, %d, %d)", x, y, z);
	}
	else if (aw == 5) {
		
	}
	else {
		printf("�������� �Է��Դϴ�."); //������ �� �̿��� �� �Է½� �ȳ����� ���
	}
	printf("\n���α׷��� �����մϴ�"); //���α׷� ���� �ȳ�����

	return 0;
}