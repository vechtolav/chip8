#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f, *g, *h;
    char ch;

    f = fopen("f.txt", "r");
    g = fopen("g.txt", "r");
    if (!f || !g) {
        printf("Ошибка открытия f.txt или g.txt\n");
        return 1;
    }

    h = fopen("h.txt", "w");

    while ((ch = fgetc(f)) != EOF)
        fputc(ch, h);

    while ((ch = fgetc(g)) != EOF)
        fputc(ch, h);

    fclose(f);
    fclose(g);
    fclose(h);

    printf("Файл h.txt создан: сначала f, затем g\n");
    return 0;
}