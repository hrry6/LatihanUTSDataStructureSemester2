#include <stdio.h>

typedef struct Stack
{
    int top;
    int array[10];
} Stack;

Stack stack;

void displayData()
{

}

void push(int value)
{

}

void pop()
{

}

void top()
{

}

void printMenu()
{
    system("cls");
    printf("            __                 __    \n");
    printf("    _______/  |______    ____ |  | __\n");
    printf("   /  ___/\\   __\\__  \\ _/ ___\\|  |/ /\n");
    printf("   \\___ \\  |  |  / __ \\\\  \\___|    <  \n");
    printf("  /____  > |__| (____  /\\___  >__|_ \\\n");
    printf("       \\/            \\/     \\/     \\/\n");
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
                top();
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