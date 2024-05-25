#include "lab.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int choice = 0;
    while (choice < 1 || choice > 7) {
        printf("1) The first laboratory work\n");
        printf("2) The second laboratory work \n");
        printf("3) The third laboratory work\n");
        printf("4) The forth laboratory work\n");
        printf("5) The fiveth laboratory work\n");
        printf("6) The sixth laboratory work\n");
        printf("7) The seventh laboratory work\n");
        printf("Enter the number of the desired laboratory work: ");
        scanf("%d", &choice);
    }
    if (choice == 1)
        lab1();
    else if (choice == 2) {
        lab2();
    } else if (choice == 3)
        lab3();
    else if (choice == 4)
        lab4();
    else if (choice == 5)
        lab5();
    else if (choice == 6)
        lab6();
    else if (choice == 7)
        lab7();

    system("pause");


    return 0;


}
