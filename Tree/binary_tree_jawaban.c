#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

// Fungsi untuk membuat node baru
Node* createNode(int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan node ke dalam BST
void insertNode(int value)
{
    Node* newNode = createNode(value);

    if(root == NULL)  
    {
        root = newNode;
        return;
    }

    Node* cursor = root;
    while(1)  
    {
        if(value < cursor->value)  
        {
            if(cursor->left == NULL) 
            {
                cursor->left = newNode;
                return;
            }
            cursor = cursor->left;
        }
        else  
        {
            if(cursor->right == NULL) 
            {
                cursor->right = newNode;
                return;
            }
            cursor = cursor->right;
        }
    }
}

// Fungsi mencari node terkecil di subtree kanan (successor)
Node* findMin(Node* node)
{
    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

// Fungsi menghapus node dalam BST
Node* deleteNode(Node* root, int value)
{
    if(root == NULL) return root; // Jika tree kosong

    if(value < root->value) 
    {
        root->left = deleteNode(root->left, value); // Rekursif ke kiri
    }
    else if(value > root->value)
    {
        root->right = deleteNode(root->right, value); // Rekursif ke kanan
    }
    else 
    {
        // Kasus 1: Node adalah leaf (tidak punya anak)
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        
        // Kasus 2: Node hanya punya 1 anak (kanan atau kiri)
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Kasus 3: Node memiliki dua anak
        Node* temp = findMin(root->right);  // Cari successor
        root->value = temp->value;  // Ganti nilai dengan successor
        root->right = deleteNode(root->right, temp->value);  // Hapus successor
    }
    return root;
}

// Fungsi inorder traversal (untuk mengecek BST)
void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main()
{
    insertNode(10);
    insertNode(5);
    insertNode(15);
    insertNode(3);
    insertNode(7);
    insertNode(13);
    insertNode(18);

    printf("Sebelum Hapus: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 10); // Menghapus node 10 (punya dua anak)

    printf("Setelah Hapus 10: ");
    inorder(root);
    printf("\n");

    return 0;
}
