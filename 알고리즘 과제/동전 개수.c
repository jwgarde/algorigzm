#include<stdio.h>
typedef struct coin { //동전 개수 구조체
	int n500;
	int n100;
	int n50;
	int n10;
}COIN;
COIN per_coin;
int coin_counting(int coin) {
	;     // 각 동전의 개수를 계산 하는 함수
	per_coin.n500 = coin / 500;
	per_coin.n100 = (coin % 500) / 100;
	per_coin.n50 = ((coin % 500) % 100) / 50;
	per_coin.n10 = (((coin % 500) % 100) % 50) / 10;
	return;
}
void input() {  //거스름돈 총액을 입력 받는 함수
	int coin = 0;
	printf("거스름돈 총액 입력");
	scanf_s("%d", &coin);
	coin_counting(coin);
	printf("500원 : %d\n100원 : %d \n50원 : %d \n10원 : %d", per_coin.n500, per_coin.n100, per_coin.n50, per_coin.n10);
}
int main(void) { //메인 함수
	input();
}