#include<stdio.h>

struct Product //product 구조체 선언
{
	int ID;
	char name[100];
	int pr;
};

void printProduct(struct Product p) { //입력받은 product 출력함수
	printf("\n상품 ID : %d",p.ID);
	printf("\n상품명 : %s", p.name);
	printf("\n가격 : %d원", p.pr);
	return;
}

int main() {
	int i;
	struct Product p[5];
	for (i = 0; i < 5; i++) { //5회 product 입력받음
		printf("상품의 정보를 입력하세요 (입력중단은 id에 0입력)\n");
		printf("상품 ID : ");
		scanf_s("%d", &p[i].ID);
		if (p[i].ID == 0) { //id=0일경우 입력중단
			break;
		}
		printf("상품명 : ");
		scanf_s("%s", p[i].name,sizeof(p[i].name));
		printf("가격 : ");
		scanf_s("%d", &p[i].pr);
		printf("\n");
	}

	printf("\n입력중단\n\n<<입력한 상품 목록>>");

	for (i = 0; i < 5; i++) {
		if (p[i].ID == 0) { //id=0일경우 출력중단
			if (i == 0) {
				printf("\n입력된 상품이 없습니다.");
			}
			break;
		}
		printProduct(p[i]);
		printf("\n");
	}

	return 0;
}