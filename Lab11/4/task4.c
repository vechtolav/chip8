#include <stdio.h>
#include <math.h>

int isPerfectSquare(int n) {
    if (n < 0) return 0;
    int root = (int)sqrt(n);
    return (root * root == n);
}

int main() {
    FILE *f, *g_even, *g_div3not7, *g_squares;
    int num;

    f = fopen("f.txt", "r");
    if (!f) {
        printf("Ошибка открытия f.txt\n");
        return 1;
    }

    g_even = fopen("g_even.txt", "w");
    g_div3not7 = fopen("g_div3not7.txt", "w");
    g_squares = fopen("g_squares.txt", "w");

    while (fscanf(f, "%d", &num) == 1) {
        if (num % 2 == 0)
            fprintf(g_even, "%d ", num);

        if (num % 3 == 0 && num % 7 != 0)
            fprintf(g_div3not7, "%d ", num);

        if (isPerfectSquare(num))
            fprintf(g_squares, "%d ", num);
    }

    fclose(f);
    fclose(g_even);
    fclose(g_div3not7);
    fclose(g_squares);

    printf("Готово: g_even.txt, g_div3not7.txt, g_squares.txt\n");
    return 0;
}