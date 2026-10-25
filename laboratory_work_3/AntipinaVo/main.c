#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void sicret(int n, char* number) {
    char p[] = "0123456789";
    int size = 10;
    int j = 1 + rand() % 9;
    number[0] = p[j];
    p[j] = p[--size];
    for (int i = 1; i < n; i++) {
        int k = rand() % size;
        number[i] = p[k];
        p[k] = p[--size];
    }
    number[n] = '\0';
}
static void score(const char* sicret, const char* g, int n, int* bulls , int* cows) {
    *bulls = 0;
    *cows = 0;
    int cnt_s[10] = { 0 }, cnt_g[10] = { 0 };
    for (int i = 0; i < n; i++) {
        if (sicret[i] == g[i]) {
            (*bulls)++;
        }
        else {
            cnt_s[sicret[i] - '0']++;
            cnt_g[g[i] - '0']++;
        }
    }
    for (int d = 0; d < 10; d++) {
        if (cnt_s[d] < cnt_g[d]) {
            *cows += cnt_s[d];
        }
        else {
            *cows += cnt_g[d];
        }
    }
}
int main(void) {
    srand((unsigned)time(NULL));
    int n = 0;
    char line[64];
    while (1) {
        printf(" (2-5): ");
        if (!fgets(line, sizeof(line), stdin)) return 0;
        if (sscanf_s(line, "%d", &n) == 1 && n >= 2 && n <= 5) break;
    }
    char secret[6];
    sicret(n, secret);
    char guess[64];
    int popitki = 0, bulls = 0, cows = 0;
    do {
        printf("popitka %d. vedite %d chisel: ", popitki + 1, n);
        scanf_s("%63s", guess, 64);
        popitki++;
        score(secret, guess, n, &bulls, &cows);
        printf("bulls : %d, cows: %d\n", bulls, cows);

    } while (bulls != n);
    printf("ygadal! chislo %s za %d popitok", secret, popitki);
    return 0;
}