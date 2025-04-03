#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int l;
    int r;
    int array[10];
} Queue;

Queue queue;

void displayData()
{

}

void push(int value)
{

}

void pop()
{

}

void front()
{

}

void printMenu()
{
    system("cls");
    printf("     ________ __   ____  __ __   ____  \n");
    printf("    / ____/  |  \\_/ __ \\|  |  \\_/ __ \\ \n");
    printf("   < <_|  |  |  /\\  ___/|  |  /\\  ___/ \n");
    printf("    \\__   |____/  \\___  >____/  \\___  >\n");
    printf("       |__|           \\/            \\/ \n");
    printf("1. Display all data\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Front\n");
    printf("5. Selesai\n");
    printf("Pilihan anda : ");
}

int main()
{
    int inputUser;
    do
    {
        printMenu();
        scanf("%d", &inputUser);
        getchar();

        system("cls");
        if(inputUser > 0 && inputUser <= 5)
        {
            if(inputUser == 1)
            {
                displayData();
            }
            else if(inputUser == 2)
            {
                int value;
                printf("Masukkan nilai : ");
                scanf("%d", &value);
                getchar();
                push(value);
            }
            else if(inputUser == 3)
            {
                pop();
            }
            else if(inputUser == 4)
            {
                front();
            }
            else if(inputUser == 5)
            {
                printf("Selesai\n");
                break;
            }
            printf("\nTekan tombol apa saja untuk melanjutkan...");
            getchar();
        }


    }while(1);
    return 0;
}