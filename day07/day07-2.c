#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{
	double x = 0;
	double y = 0;
	int count = 0, in_count = 0; //���� ��ġ�� ��� Ƚ��, ���� ��ä�þȿ� �� Ƚ��
	double sum = 0; //x�� y�� �̿��Ͽ� ���� ���� ��ä���� �߽� ������ �Ÿ�
	double r = 1.0; //��ä���� ������
	double pi; // ���� �� ������ ���� ���� ���̰�
	int j;
	srand(time(NULL));

	for (int i = 1; i < 101; i++) {
		
		while (count < 10000000*i) {

			x = (double)rand() / (double)RAND_MAX;
			y = (double)rand() / (double)RAND_MAX; //���� x�� y��ǥ �������� ����
			x = pow(x, 2);
			y = pow(y, 2);
			sum = sqrt(x + y); //���� ��ä���� �߽ɰ��� �Ÿ�
			if (sum < r) {
				in_count++; //���� ��ä�ÿ� ������ ��� ����
			}
			count++;
		}
		pi = 4.0 * in_count / count;//���̰� ���ϱ�
		printf("%3d%%����.. ������ : %f\t",i,pi);//���൵ ǥ��
		for (j=0; j <20; j++) { //�׸�� ���൵ ǥ��
			if (j<=(i-1)/5) {
				printf("��");
			}
			else {
				printf("��");
			}
		}
		printf("\n");
	}
	




	return 0;
}