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
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(Node* newNode)
{
    stack.nodes[stack.top] = newNode;
    stack.top++;
}

Node* pop()
{
    stack.top--;
    return stack.nodes[stack.top];
}

void prefixToTree()
{
    stack.top = 0;

    int n = strlen(str);
    for(int i = n - 1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            continue;
        }
        else if(str[i] >= '0' && str[i] <= '9')
        {
            push(createNode(str[i]));
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            Node* op = createNode(str[i]);
            op->left = pop();
            op->right = pop();
            push(op);
        }
    }
    root = stack.nodes[0];
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
    printf("    __________                        ___________                       \n");
    printf("    \\______   \\_______   ____         \\__    ___/______   ____   ____   \n");
    printf("     |     ___/\\_  __ \\_/ __ \\   ______ |    |  \\_  __ \\_/ __ \\_/ __ \\  \n");
    printf("     |    |     |  | \\/\\  ___/  /_____/ |    |   |  | \\/\\  ___/\\  ___/  \n");
    printf("     |____|     |__|    \\___  >         |____|   |__|    \\___  >\\___  > \n");
    printf("                            \\/                               \\/     \\/  \n");
    printf("\n");
    printf("Masukkan string prefix (tanpa spasi) : ");
    scanf("%[^\n]", str);
    getchar();

    prefixToTree();

    printf("Prefix : ");
    printPrefix(root);
    printf("\nInfix : ");
    printInfix(root);
    printf("\nPostfix : ");
    printPostfix(root);

    return 0;
}