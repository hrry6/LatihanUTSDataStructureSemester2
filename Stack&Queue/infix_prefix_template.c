#include <stdio.h>
#include <string.h>

typedef struct Stack
{
    int top;
    char str[100];
} Stack;

Stack stack;
Stack stringAwal;
Stack prefixString;

int symbolLevel(char symbol)
{

}

void push_prefixString(char value)
{

}

void push_stack(char value)
{

}

void pop_stack()
{

}

void reverseString(char *str)
{

}

void in_Pre()
{

}

int main()
{
    stack.top = 0;
    prefixString.top = 0;
    stringAwal.top = 0;
    printf("    .___                __________                  \n");
    printf("    |   | ____          \\______   \\_______   ____   \n");
    printf("    |   |/    \\   ______ |     ___/\\_  __ \\_/ __ \\  \n");
    printf("    |   |   |  \\ /_____/ |    |     |  | \\/\\  ___/  \n");
    printf("    |___|___|  /         |____|     |__|    \\___  > \n");
    printf("             \\/                                 \\/  \n");
    printf("Masukkan infix string (tanpa spasi) : ");
    scanf("%s", stringAwal.str);
    getchar();
    in_Pre();

    return 0;
}
