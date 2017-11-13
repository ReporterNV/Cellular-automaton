#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

    long long int SUMM = 0;
    long long int SUM = 0;
    unsigned short N = 0; //N-длина строки
    unsigned short L = 0; //L-Длина столбца
    int NUM = 30;

    if(argc>1)
    NUM = atoi(argv[1]);
    else
    puts("No argument. Will be used rule 30");
 
    FILE *log = fopen("Logs.txt", "a");

    do {
        puts("Enter the length of the line(from 0 to 6000)");
        scanf("%hu", &N);
    } while ((N > 60000) || (N < 3));

    _Bool *a = malloc(sizeof(_Bool)*(N + 1));
    _Bool *b = malloc(sizeof(_Bool)*(N + 1));

    //Массив для подсчёта по оси х
    long long *k = malloc(sizeof(long long)*(N + 1));

    do {
        puts("Enter the number of calculations(from 0 to 16000)");
        scanf("%hu", &L);
    } while ((L >= 60000) || (L <= 0));

    printf("Enter the address of the cell in which you want to assign 1.\nEnter 0 to finish input.\n");

    fprintf(log, "\n\n%d\n%d\n", N, L);

    while (1) {
        scanf("%d", &SUMM);
        if (SUMM == 0)break;
        else if (SUMM > 0 && SUMM <= N) {
            a[SUMM] = 1;
            fprintf(log, "%d-", SUMM);
            puts("Success");
        } else
            puts("Not included in the range");}

    fclose(log);

    FILE *file   = fopen("Evolve.txt", "w");
    FILE *X_axis = fopen("axis_X.txt", "w");
    FILE *Y_axis = fopen("axis_Y.txt", "w");

//Для вывода 1-ой строки
    for (int j = 1; j <= N; j++) {
        if (a[j] == 0)
            fprintf(file, " ");
        else {
            fprintf(file, "1");
            k[j] += 1;
        }
    }

    fprintf(file, "\n");

    //Условие для проверки 
    for (int i = 0; i < L; i++) {
        for (int j = 1; j <= N; j++) {
            //Перебор
            if (j > 1 && j < N) {
                //Условие
                if ((a[j - 1] == 1)&&(a[j] == 1)&&(a[j + 1] == 1)&&((NUM >> 7) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 1)&&(a[j] == 1)&&(a[j + 1] == 0)&&((NUM >> 6) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 1)&&(a[j] == 0)&&(a[j + 1] == 1)&&((NUM >> 5) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 1)&&(a[j] == 0)&&(a[j + 1] == 0)&&((NUM >> 4) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 0)&&(a[j] == 1)&&(a[j + 1] == 1)&&((NUM >> 3) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 0)&&(a[j] == 1)&&(a[j + 1] == 0)&&((NUM >> 2) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 0)&&(a[j] == 0)&&(a[j + 1] == 1)&&((NUM >> 1) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[j - 1] == 0)&&(a[j] == 0)&&(a[j + 1] == 0)&&(NUM % 2 == 1)) {
                    b[j] = 1;
                } else {
                    b[j] = 0;
                }
            } else
                if (j == 1) {
                //Условие
                if ((a[N] == 1)&&(a[j] == 1)&&(a[j + 1] == 1)&&((NUM >> 7) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 1)&&(a[j] == 1)&&(a[j + 1] == 0)&&((NUM >> 6) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 1)&&(a[j] == 0)&&(a[j + 1] == 1)&&((NUM >> 5) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 1)&&(a[j] == 0)&&(a[j + 1] == 0)&&((NUM >> 4) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 0)&&(a[j] == 1)&&(a[j + 1] == 1)&&((NUM >> 3) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 0)&&(a[j] == 1)&&(a[j + 1] == 0)&&((NUM >> 2) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 0)&&(a[j] == 0)&&(a[j + 1] == 1)&&((NUM >> 1) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[N] == 0)&&(a[j] == 0)&&(a[j + 1] == 0)&&(NUM % 2 == 1)) {
                    b[j] = 1;
                } else {
                    b[j] = 0;
                }
            } else
                if (j == N) {
                //Условие
                if ((a[1] == 1)&&(a[j] == 1)&&(a[N] == 1)&&((NUM >> 7) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 1)&&(a[j] == 1)&&(a[N] == 0)&&((NUM >> 6) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 1)&&(a[j] == 0)&&(a[N] == 1)&&((NUM >> 5) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 1)&&(a[j] == 0)&&(a[N] == 0)&&((NUM >> 4) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 0)&&(a[j] == 1)&&(a[N] == 1)&&((NUM >> 3) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 0)&&(a[j] == 1)&&(a[N] == 0)&&((NUM >> 2) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 0)&&(a[j] == 0)&&(a[N] == 1)&&((NUM >> 1) % 2 == 1)) {
                    b[j] = 1;
                } else
                    if ((a[1] == 0)&&(a[j] == 0)&&(a[N] == 0)&&(NUM % 2 == 1)) {
                    b[j] = 1;
                } else {
                    b[j] = 0;
                }
            }
        }//Конец перебора


        //Вывод в табл 1/0
       for (int j = 1; j <= N; j++) {
           a[j] = b[j];
           if (a[j] == 0)
               fprintf(file, " ");
           else {
               fprintf(file, "1");
               //
               SUM ++;
               k[j]++;
           }
       }

        fprintf(X_axis, "%d:  %d\n", i + 1, SUM);
        fprintf(file, "\n");
        SUMM += SUM;
        SUM = 0;

        for (int i = 1; i <= N; i++)
            fprintf(Y_axis, "%lu|", k[i]);
        fprintf(Y_axis, "\n");
        
    }
   
    fprintf(X_axis, "\n\t Итог: %d", SUMM);
    fclose(file);
    fclose(Y_axis);
    fclose(X_axis);
    free(a);
    free(b);
    free(k);

    return 0;
}