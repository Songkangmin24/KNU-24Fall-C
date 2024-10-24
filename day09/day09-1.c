#include<stdio.h>

int x, y, z; 
struct vector //벡터 선언
{
	int x, y, z;
};

void add(struct vector p1, struct vector p2) { //벡터의 합 함수
	x = p1.x + p2.x;
	y = p1.y + p2.y;
	z = p1.z + p2.z;
	return;
}
void sub(struct vector p1, struct vector p2) { //벡터의 차 함수
	x = p1.x - p2.x;
	y = p1.y - p2.y;
	z = p1.z - p2.z;
	return;
}
int in_s(struct vector p1, struct vector p2) { //벡터의 내적 함수
	int sum;
	sum = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	return sum;
}
void out_s(struct vector p1, struct vector p2) { //벡터의 외적 함수
	x = p1.y * p2.z - p1.z * p2.y;
	y = p1.z * p2.x - p1.x * p2.z;
	z = p1.x * p2.y - p1.y * p2.x;
	return;
}

void print_vector(struct vector p) { //입력받은 벡터를 출력하는 함수
	printf("vector (%d,%d,%d)\n",p.x,p.y,p.z);
}


int main() {
	int aw,sum;
	struct vector p[2]; //벡터의 개수 2로 설정
	
	printf("vector1 x : "); //벡터 1 입력
	scanf_s("%d", &p[0].x);
	printf("vector1 y : ");
	scanf_s("%d", &p[0].y);
	printf("vector1 z : ");
	scanf_s("%d", &p[0].z);

	printf("\n");

	printf("vector2 x : "); //벡터 2 입력
	scanf_s("%d", &p[1].x);
	printf("vector2 y : ");
	scanf_s("%d", &p[1].y);
	printf("vector2 z : ");
	scanf_s("%d", &p[1].z);


	printf("\n");
	print_vector(p[0]); //입력받은 벡터 출력
	print_vector(p[1]);

	printf("1.백터의 합\n2.백터의 차\n3.백터의 외적\n4.백터의 내적\n5.종료\n"); //명령의 종류 출력
	printf("명령입력 : ");
	scanf_s("%d",&aw);
	
	if (aw == 1) { //사용자가 입력한 값에 따라 명령 수행
		add(p[0], p[1]);
		printf("백터의 합은 (%d, %d, %d)",x,y,z );
	}else if (aw == 2) {
		sub(p[0], p[1]);
		printf("백터의 차는 (%d, %d, %d)", x, y, z);
	}
	else if (aw == 3) {
		sum=in_s(p[0], p[1]);
		printf("백터의 내적은 %d", sum);
	}
	else if (aw == 4) {
		out_s(p[0], p[1]);
		printf("백터의 외적은 (%d, %d, %d)", x, y, z);
	}
	else if (aw == 5) {
		
	}
	else {
		printf("옳지않은 입력입니다."); //지정된 값 이외의 값 입력시 안내문구 출력
	}
	printf("\n프로그램을 종료합니다"); //프로그램 종료 안내문구

	return 0;
}