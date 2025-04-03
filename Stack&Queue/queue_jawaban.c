#include <stdio.h>

typedef struct Queue
{
    int l;
    int r;
    int array[10];
} Queue;

Queue queue;

void displayData()
{
    int n = sizeof(queue.array) / sizeof(queue.array[0]);
    
    printf("L : %d\n", queue.l);
    printf("R : %d\n", queue.r);
    printf("Array : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", queue.array[i]);
    }
}

void push(int value)
{
    if(queue.r == 10)
    {
        printf("Array sudah penuh\n");
        return;
    }

    queue.array[queue.r] = value;
    queue.r += 1;
}

void pop()
{
    if(queue.l == queue.r)
    {
        printf("Array kosong\n");
        return;
    }

    queue.array[queue.l] = 0;
    queue.l += 1;

    if(queue.l == queue.r)
    {
        queue.l = 0;
        queue.r = 0;
    }
}

void front()
{
    if(queue.l == queue.r)
    {
        printf("Array kosong\n");
        return;
    }

    printf("Front : %d\n", queue.array[queue.l]);
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
    printf("4. Top\n");
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