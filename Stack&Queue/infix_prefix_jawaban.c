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
    if (symbol == '(') return 0;  
    if (symbol == ')') return 4;  
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return -1; 
}

void push_prefixString(char value)
{
    prefixString.str[prefixString.top] = value;
    prefixString.top += 1;
    prefixString.str[prefixString.top] = '\0';
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
        push_prefixString(stack.str[stack.top - 1]);
        stack.top--;
    }
}

void reverseString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void in_Pre()
{
    reverseString(stringAwal.str);

    for (int i = 0; i < strlen(stringAwal.str); i++)
    {
        if (stringAwal.str[i] == '(')
            stringAwal.str[i] = ')';
        else if (stringAwal.str[i] == ')')
            stringAwal.str[i] = '(';
    }

    int n = strlen(stringAwal.str);
    for (int i = 0; i < n; i++)
    {
        char current = stringAwal.str[i];

        if (current >= '0' && current <= '9')
        {
            push_prefixString(current);
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

    reverseString(prefixString.str);

    printf("Prefix String: %s\n", prefixString.str);
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
