#include <stdio.h>
#include <string.h>

typedef struct Stack
{
    int top;
    char str[100];
} Stack;

Stack stack;
Stack stringAwal;
Stack postfixString;

int symbolLevel(char symbol)
{

}

void push_postfixString(char value)
{

}

void push_stack(char value)
{

}

void pop_stack()
{

}

void in_Pos()
{

}

int main()
{
    stack.top = 0;
    postfixString.top = 0;
    stringAwal.top = 0;

    printf("    .___                __________              \n");
    printf("    |   | ____          \\______   \\____  ______ \n");
    printf("    |   |/    \\   ______ |     ___/  _ \\/  ___/ \n");
    printf("    |   |   |  \\ /_____/ |    |  (  <_> )___ \\  \n");
    printf("    |___|___|  /         |____|   \\____/____  > \n");
    printf("             \\/                             \\/  \n");
    printf("Masukkan infix string (tanpa spasi) : ");
    scanf("%s", stringAwal.str);
    getchar();
    in_Pos();

    return 0;
}
