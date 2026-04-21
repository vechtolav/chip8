#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *f, *g;
    char word[256];
    int c, inWord = 0, spaceWritten = 0;

    f = fopen("f.txt", "r");
    g = fopen("g.txt", "w");

    if (!f || !g) {
        printf("Ошибка открытия файлов\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), f)) {
        int i = 0;
        while (line[i]) {
            if (isspace(line[i])) {
                if (!spaceWritten) {
                    fputc(' ', g);
                    spaceWritten = 1;
                }
                i++;
                continue;
            }

            int start = i;
            while (line[i] && !isspace(line[i]))
                i++;
            int len = i - start;

            if (len > 1) {
                for (int j = start; j < i; j++)
                    fputc(line[j], g);
                spaceWritten = 0; 
            } else {
                spaceWritten = 0; 
            }
        }
        fputc('\n', g);
        spaceWritten = 0;
    }

    fclose(f);
    fclose(g);

    printf("Готово: g.txt (удалены однобуквенные слова и лишние пробелы)\n");
    return 0;
}