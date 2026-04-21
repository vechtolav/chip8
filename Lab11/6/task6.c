#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARS 100
#define MAX_LEN 50

typedef struct {
    char mark[MAX_LEN];
    char number[MAX_LEN];
    char owner[MAX_LEN];
} Car;

int main() {
    FILE *f, *g;
    Car cars[MAX_CARS];
    int count = 0, i, j;

    f = fopen("f.txt", "r");
    if (!f) {
        printf("Ошибка открытия f.txt\n");
        return 1;
    }

    while (fscanf(f, "%s %s %s", 
                  cars[count].mark, 
                  cars[count].number, 
                  cars[count].owner) == 3) {
        count++;
        if (count >= MAX_CARS) break;
    }
    fclose(f);

    if (count == 0) {
        printf("Файл пуст или имеет неверный формат\n");
        return 1;
    }

    // 2. Запись результатов в g
    g = fopen("g.txt", "w");
    if (!g) {
        printf("Ошибка создания g.txt\n");
        return 1;
    }

    char targetMark[MAX_LEN];
    printf("Введите марку для поиска: ");
    scanf("%s", targetMark);

    fprintf(g, "=== Автомобили марки %s ===\n", targetMark);
    int found = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(cars[i].mark, targetMark) == 0) {
            fprintf(g, "Владелец: %s, Номер: %s\n", cars[i].owner, cars[i].number);
            found++;
        }
    }
    if (!found) {
        fprintf(g, "Автомобилей марки %s не найдено\n", targetMark);
    }

    fprintf(g, "\n=== Количество автомобилей по маркам ===\n");

    char uniqueMarks[MAX_CARS][MAX_LEN];
    int counts[MAX_CARS] = {0};
    int uniqueCount = 0;

    for (i = 0; i < count; i++) {
        int foundMark = 0;
        for (j = 0; j < uniqueCount; j++) {
            if (strcmp(uniqueMarks[j], cars[i].mark) == 0) {
                counts[j]++;
                foundMark = 1;
                break;
            }
        }
        if (!foundMark) {
            strcpy(uniqueMarks[uniqueCount], cars[i].mark);
            counts[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    for (i = 0; i < uniqueCount; i++) {
        fprintf(g, "%s: %d шт.\n", uniqueMarks[i], counts[i]);
    }

    fclose(g);
    printf("Результат записан в файл g.txt\n");
    return 0;
}