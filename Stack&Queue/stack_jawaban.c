#include <stdio.h>

typedef struct Stack
{
    int top;
    int array[10];
} Stack;

Stack stack;

void displayData()
{
    int n = sizeof(stack.array) / sizeof(stack.array[0]);
    
    printf("Top : %d\n", stack.top);
    printf("Array : ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", stack.array[i]);
    }
    
}

void push(int value)
{
    if(stack.top == 10)
    {
        printf("Array sudah penuh\n");
        return;
    }
    stack.array[stack.top] = value;
    stack.top += 1;
}

void pop()
{
    if(stack.top == 0)
    {
        printf("Array kosong\n");
        return;
    }

    stack.top--;
    stack.array[stack.top] = 0;
}

void top()
{
    if(stack.top == 0)
    {
        printf("Array kosong\n");
        return;
    }

    printf("Top : %d\n", stack.array[stack.top - 1]);
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