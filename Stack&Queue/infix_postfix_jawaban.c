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
    if (symbol == '(') return 0;  
    if (symbol == ')') return 4;  
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return -1;  
}

void push_postfixString(char value)
{
    postfixString.str[postfixString.top] = value;
    postfixString.top += 1;
    postfixString.str[postfixString.top] = '\0';
}

void push_stack(char value)
{
    stack.str[stack.top] = value;
    stack.top += 1;
}

void pop_stack()
{
    if (stack.top > 0)
    {
        push_postfixString(stack.str[stack.top - 1]);
        stack.top--;
    }
}

void in_Pos()
{
    int n = strlen(stringAwal.str);
    for (int i = 0; i < n; i++)
    {
        char current = stringAwal.str[i];

        if (current >= '0' && current <= '9')
        {
            push_postfixString(current);
        }
        else if (current == '(')
        {
            push_stack(current); 
        }
        else if (current == ')')
        {
            while (stack.top > 0 && stack.str[stack.top - 1] != '(')
            {
                pop_stack();
            }
            stack.top--;
        }
        else
        {
            while (stack.top > 0 && symbolLevel(stack.str[stack.top - 1]) >= symbolLevel(current))
            {
                pop_stack();
            }
            push_stack(current);
        }
    }

    while (stack.top > 0)
    {
        pop_stack();
    }

    printf("Postfix String: %s\n", postfixString.str);
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
