#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Stack
{
    int top;
    Node* nodes[100];
} Stack;

Stack stack;
Node* root = NULL;
char str[100];

Node* createNode(char value)
{

}

void push(Node* newNode)
{

}

Node* pop()
{

}

void postfixToTree()
{

}

void printInfix(Node* root)
{

}

void printPrefix(Node* root)
{

}

void printPostfix(Node* root)
{

}

int main()
{
    printf("    __________               __          ___________                       \n");
    printf("    \\______   \\____  _______/  |_        \\__    ___/______   ____   ____   \n");
    printf("     |     ___/  _ \\/  ___/\\   __\\  ______ |    |  \\_  __ \\_/ __ \\_/ __ \\  \n");
    printf("     |    |  (  <_> )___ \\  |  |   /_____/ |    |   |  | \\/\\  ___/\\  ___/  \n");
    printf("     |____|   \\____/____  > |__|           |____|   |__|    \\___  >\\___  > \n");
    printf("                        \\/                                      \\/     \\/  \n");
    printf("\n");
    printf("Masukkan string postfix (tanpa spasi) : ");
    scanf("%[^\n]", str);
    getchar();

    postfixToTree();

    printf("Prefix : ");
    printPrefix(root);
    printf("\nInfix : ");
    printInfix(root);
    printf("\nPostfix : ");
    printPostfix(root);

    return 0;
}