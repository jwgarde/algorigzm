#include<stdio.h>
typedef struct coin { //���� ���� ����ü
	int n500;
	int n100;
	int n50;
	int n10;
}COIN;
COIN per_coin;
int coin_counting(int coin) {
	;     // �� ������ ������ ��� �ϴ� �Լ�
	per_coin.n500 = coin / 500;
	per_coin.n100 = (coin % 500) / 100;
	per_coin.n50 = ((coin % 500) % 100) / 50;
	per_coin.n10 = (((coin % 500) % 100) % 50) / 10;
	return;
}
void input() {  //�Ž����� �Ѿ��� �Է� �޴� �Լ�
	int coin = 0;
	printf("�Ž����� �Ѿ� �Է�");
	scanf_s("%d", &coin);
	coin_counting(coin);
	printf("500�� : %d\n100�� : %d \n50�� : %d \n10�� : %d", per_coin.n500, per_coin.n100, per_coin.n50, per_coin.n10);
}
int main(void) { //���� �Լ�
	input();
}