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
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void pushOperand(Node* newNode)
{
    operandStack.nodes[operandStack.top] = newNode;
    operandStack.top++;
}

void pushOperator(Node* newNode)
{
    operatorStack.nodes[operatorStack.top] = newNode;
    operatorStack.top++;
}

Node* popOperator()
{
    operatorStack.top--;
    return operatorStack.nodes[operatorStack.top];
}

Node* popOperand()
{
    operandStack.top--;
    return operandStack.nodes[operandStack.top];
}

int operatorRank(char operator)
{
    if(operator == '*' || operator == '/') return 2;
    if(operator == '+' || operator == '-') return 1;
    return 0;
}

void arrangeNode()
{
    Node* newNode = popOperator();
    newNode->right = popOperand();
    newNode->left = popOperand();
    pushOperand(newNode);
}

void infixToTree()
{
    operatorStack.top = 0;
    operandStack.top = 0;

    for(int i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
        {
            continue;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            pushOperand(createNode(str[i]));
        }
        else if(str[i] == '(')
        {
            pushOperator(createNode(str[i]));
        }
        else if(str[i] == ')')
        {
            while(operatorStack.top > 0 && operatorStack.nodes[operatorStack.top - 1]->value != '(')
            {
                arrangeNode();
            }
            operatorStack.top--;
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while(operatorStack.top > 0 && operatorRank(operatorStack.nodes[operatorStack.top - 1]->value) >= operatorRank(str[i]))
            {
                arrangeNode();
            }
            pushOperator(createNode(str[i]));
        }
    }

    while(operatorStack.top > 0)
    {
        arrangeNode();
    }

    root = operandStack.nodes[0];
}

void printInfix(Node* root)
{
    if(root == NULL) return;

    if(root->left) printf("(");
    printInfix(root->left);
    printf("%c", root->value);
    printInfix(root->right);
    if(root->right) printf(")");
}

void printPrefix(Node* root)
{
    if(root == NULL) return;

    printf("%c", root->value);
    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(Node* root)
{
    if(root == NULL) return;

    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c", root->value);
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
