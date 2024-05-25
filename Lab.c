#include "lab.h"
#include <stdio.h>
int lab1()
{

    int P, A, B, C;

    printf("input A: ");
    scanf_s("%d", &A);
    printf("input B: ");
    scanf_s("%d", &B);
    printf("input C: ");
    scanf_s("%d", &C);

    P = (A + B * B) / (C - A);
    printf("P = %d", P);
}

int lab2()
{

    {
        float s, a, e, i, sign;
        printf("e = ");
        scanf("%f", &e);
        s = 0;
        sign = 1;
        i = 0;
        while(i < e)
        {
            a = (3+i)/(1+3*i);
            s = s + a*sign;
            sign = -sign;
            i++;
            //printf("s = %f\n", s);
        }
        printf("s = %f\n", s);
        return 0;
    }

}

int lab3()  {

/*
#define YES 1
#define NO 0

    int c;
    int firstletter = ' ';
    int prevletter = '_';
    int endofword = YES;
    int count = 0;

    while ((c = getchar()) != '.')
    {
        if (endofword == YES)
        {
            firstletter = c;
            endofword = NO;
        }

        if (c == ' ' || c == '.' || c == '\n' ||  c == ',')
        {
            endofword = YES;

            if (prevletter == firstletter)
                count += 1;
        }

        prevletter = c;
    }

    printf("count: %d", count);

    return 0;
}
*/
    int c;
    int firstletter = ' ';
    int prevletter = '_';
    int endofword = YES;
    int count = 0;
    int letter_count[256] = {0};

    while ((c = getchar()) != '.') {
        if (endofword == YES) {
            firstletter = c;
            endofword = NO;
            for (int i = 0; i < 256; i++) {
                letter_count[i] = 0;
            }
        }

        if (c != ' ' && c != '.' && c != '\n' && c != ',') {
            letter_count[c]++;
        }

        if (c == ' ' || c == '.' || c == '\n' || c == ',') {
            endofword = YES;

            int more_than_two = NO;
            for (int i = 0; i < 256; i++) {
                if (letter_count[i] > 2) {
                    more_than_two = YES;
                    break;
                }
            }

            if (prevletter == firstletter && !more_than_two)
                count += 1;
        }

        prevletter = c;
    }

    printf("count: %d\n", count);

    return 0;
}

int lab4() {

getchar();
    int i = 0;
    int j = 0;
    char c;
    char line[MAX];
    char buffer[MAX];
    int flag = FALSE;
    int size = sizeof(buffer)/sizeof(char);

    fgets( buffer, MAX, stdin);

    do {
        c = buffer[i];

        if (c == ',' && i + 2 < size) {
            line[j++] = ' ';
            flag = TRUE;
            i += 2;
        }

        if (flag == TRUE) {
            if (buffer[i] == ' ' || buffer[i] == '.' || buffer[i] == '\t') {
                flag = FALSE;
            }
            i++;
            continue;
        }

        line[j] = c;
        i++;
        j++;
    } while (c != '\0');

    line[j] = '\0';
    //puts(line);
    for (i = 0; line[i] != '\0'; i++) {
        putchar(line[i]);
    }

    return 0;
}

int lab5(){
/*    int arr[N];
    int i;
    int d;
    int b;

    for(i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    d = arr[1] - arr[0];

    for(i = 0; i < N; i++)
    {
        b = (arr[i + 1] - arr[0]) / (i + 1);
        if(b != d)
        break;
    }
    i++;

    if(i < N)
        printf("thouse elements are not progressoin :(");

    else
        printf("thouse elements are progressoin  :)");

    return 0;

}

//1 3 5 7 9 11 13 15 17 19

*/



struct name {
    int min;
    int max;
    float avg;
    char progr;
};
    int arr[N];
    int i;
    float sum = 0; // Используем переменную для суммирования
    struct name sequence; // Создание переменной структуры

    // Ввод значений в массив и суммирование
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Инициализация минимального и максимального значения после ввода
    sequence.min = arr[0];
    sequence.max = arr[0];

    // Проверка на арифметическую прогрессию и обновление минимального и максимального значения
    int d = arr[1] - arr[0]; // Разность прогрессии
    sequence.progr = 'Y'; // Предполагаем, что есть прогрессия
    for(i = 1; i < N; i++) {
        if(arr[i] - arr[i - 1] != d) { // Проверка на арифметическую прогрессию
            sequence.progr = 'N'; // Если не прогрессия, устанавливаем 'N'
            break;
        }
        if(arr[i] < sequence.min) sequence.min = arr[i]; // Обновление минимального значения
        if(arr[i] > sequence.max) sequence.max = arr[i]; // Обновление максимального значения
    }

    // Вычисление среднего значения
    sequence.avg = sum / N;

    // Вывод результатов
    if(sequence.progr == 'N')
        printf("no:(\n");
    else
        printf("yes :)\n");

    printf("Min: %d\n", sequence.min);
    printf("Max: %d\n", sequence.max);
    printf("Avg: %.2f\n", sequence.avg);
    printf("Progression: %c\n", sequence.progr);

    return 0;
}

int lab6()
{


long long int x[K][N];
long long int b, max, min, strmax, strmin;
long long int i, j;
    for(i = 0; i < K; i++)
        for(j = 0; j < N; j++)
            scanf("%lld", &x[i][j]);
    max = x[0][0];
    for(i = 0; i < K; i++)
        for(j = 0; j < N; j++)
            if(x[i][j] > max)
            {
               max = x[i][j];
               strmax = i;
                }
    min = x[0][0];
    for(i = 0; i < K; i++)
        for(j = 0; j < N; j++)
            if(x[i][j] < min)
            {
                min = x[i][j];
                strmin = i;
            }
    for(j = 0; j < N; j++)
    {
        b = x[strmax][j];
        x[strmax][j] = x[strmin][j];
        x[strmin][j] = b;
    }
    if(strmin == strmax)
        printf("max and min are situated in the same string");
    else
    {
        for( i = 0; i < K; i++ )
        {
            for( j = 0; j < N; j++ )
                printf("%4lld ", x[i][j]);
            printf("\n");
        }
    }
    return 0;
}
/*
15 47 56 89
10 12 13 17
1 2 3 4
*/
int lab7() {
    long z;
    unsigned long y, c, mask = 1;
    int counter = 0;
    int pos = 0;

    printf("Enter an integer: ");
    scanf("%ld", &z);

    c = y = (unsigned long)z;


    while (y != 0) {
        counter += y & mask;
        y >>= 1;
    }


    if (z < 0) {
        printf("The number is negative. Counting set bits excluding sign bit.\n");
    } else {
        printf("The number is positive or zero.\n");
    }

    if (counter % 2 != 0) {
        y = c;
        counter = 0;
        pos = 1;

        int middle1Found = 0, middle2Found = 0;

        while (y != 0) {

            if (z < 0 && (y & (1 << (sizeof(long) * 8 - 1)))) {
                y <<= 1;
                continue;
            }

            counter += y & mask;


            if (counter == (counter % 2 == 0 ? (counter - 1) / 2 : counter / 2)) {
                if (!middle1Found) {
                    printf("Position 1: %d\n", pos);
                    middle1Found = 1;
                } else if (!middle2Found) {
                    printf("Position 2: %d\n", pos);
                    middle2Found = 1;
                    break;
                }
            }
            pos++;
            y >>= 1;
        }

        if (!middle2Found) {
            printf("NOOOO\n");
        }
    } else {
        printf("The number is even. No two middle elements.\n");
    }

    return 0;
}