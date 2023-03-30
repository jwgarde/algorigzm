#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int find_fake_coin(int coins[], int start, int end);

int main() {
    int coin_count;
    printf("동전의 개수를 입력하세요: ");
    scanf("%d", &coin_count);

    int* coins = (int*)malloc(sizeof(int) * coin_count);

    for (int i = 0; i < coin_count; i++) {
        coins[i] = 1;
    }

    srand(time(NULL));
    int fake_index = rand() % coin_count;
    coins[fake_index] = 0;

    printf("가짜 동전의 인덱스: %d\n", fake_index);
    int found_index = find_fake_coin(coins, 0, coin_count - 1);
    printf("찾은 인덱스: %d\n", found_index);

    free(coins);
    return 0;
}

int find_fake_coin(int coins[], int start, int end) {
    int len = end - start + 1;

    if (len == 1) return start;

    int left_end = start + (len / 2) - 1;
    int right_start = left_end + 1;

    int left_weight = 0, right_weight = 0;
    for (int i = start; i <= left_end; i++) {
        left_weight += coins[i];
    }
    for (int i = right_start; i <= end; i++) {
        right_weight += coins[i];
    }

    if (left_weight < right_weight) {
        return find_fake_coin(coins, start, left_end);
    }

    else {
        return find_fake_coin(coins, right_start, end);
    }
}