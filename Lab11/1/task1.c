#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1, *f2, *h;
    char ch;

    f1 = fopen("f1.txt", "r");
    f2 = fopen("f2.txt", "r");
    if (!f1 || !f2) {
        printf("Ошибка открытия f1 или f2\n");
        return 1;
    }

    h = fopen("h.txt", "w");

    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, h);
    fclose(f1);

    f1 = fopen("f1.txt", "w");
    rewind(f2); 
    while ((ch = fgetc(f2)) != EOF)
        fputc(ch, f1);
    fclose(f1);
    fclose(f2);

    f2 = fopen("f2.txt", "w");
    rewind(h);
    while ((ch = fgetc(h)) != EOF)
        fputc(ch, f2);

    fclose(f2);
    fclose(h);

    printf("Файлы успешно обменяны\n");
    return 0;
}

