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

Stack operatorStack;
Stack operandStack;
Node* root = NULL;
char str[100];

Node* createNode(char value)
{

}

void pushOperand(Node* newNode)
{

}

void pushOperator(Node* newNode)
{

}

Node* popOperator()
{

}

Node* popOperand()
{

}

int operatorRank(char operator)
{

}

void arrangeNode()
{

}

void infixToTree()
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
    printf("    .___               ___________                       \n");
    printf("    |   | ____         \\__    ___/______   ____   ____   \n");
    printf("    |   |/    \\   ______ |    |  \\_  __ \\_/ __ \\_/ __ \\  \n");
    printf("    |   |   |  \\ /_____/ |    |   |  | \\/\\  ___/\\  ___/  \n");
    printf("    |___|___|  /         |____|   |__|    \\___  >\\___  > \n");
    printf("             \\/                               \\/     \\/ \n");
    printf("\n");
    printf("Masukkan string infix (tanpa spasi) : ");
    scanf("%[^\n]", str);
    getchar();

    infixToTree();

    printf("Prefix : ");
    printPrefix(root);
    printf("\nInfix : ");
    printInfix(root);
    printf("\nPostfix : ");
    printPostfix(root);

    return 0;
}
