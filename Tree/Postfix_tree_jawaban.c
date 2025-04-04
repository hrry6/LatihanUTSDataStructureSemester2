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

void postfixToTree()
{
    stack.top = 0;

    int n = strlen(str);
    for(int i = 0; i < n; i++)
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
            op->right = pop();
            op->left = pop();
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