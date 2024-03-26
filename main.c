#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *input, *output;
    char filename[100], ch;
    int count = 0;

    // Открытие файла для чтения
    printf("Введите имя файла: ");
    scanf("%s", filename);
    input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Ошибка открытия файла\n");
        exit(1);
    }

    // Открытие файла для записи
    output = fopen("result.txt", "w");
    if (output == NULL)
    {
        printf("Ошибка открытия файла\n");
        exit(1);
    }

    // Обработка файла
    while ((ch = fgetc(input)) != EOF)
    {
        if (isdigit(ch))
        {
            count++;
        }
        if (ch == '\n')
        {
            fprintf(output, "Количество чисел в строке: %d\n", count);
            count = 0;
        }
    }

    // Закрытие файлов
    fclose(input);
    fclose(output);

    printf("Готово! Результаты записаны в файл result.txt\n");

    return 0;
}
