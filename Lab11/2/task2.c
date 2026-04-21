#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f, *g;
    long i, size;
    char ch;

    f = fopen("f.txt", "r");
    if (!f) {
        printf("Ошибка открытия f.txt\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);  

    g = fopen("g.txt", "w");

    for (i = size - 1; i >= 0; i--) {
        fseek(f, i, SEEK_SET);
        ch = fgetc(f);
        fputc(ch, g);
    }

    fclose(f);
    fclose(g);

    printf("Файл g.txt записан в обратном порядке\n");
    return 0;
}