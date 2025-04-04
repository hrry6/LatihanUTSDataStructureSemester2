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

}

// Fungsi untuk menyisipkan node ke dalam BST
void insertNode(int value)
{

}

// Fungsi mencari node terkecil di subtree kanan (successor)
Node* findMin(Node* node)
{

}

// Fungsi menghapus node dalam BST
Node* deleteNode(Node* root, int value)
{

}

// Fungsi inorder traversal (untuk mengecek BST)
void inorder(Node* root)
{

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
