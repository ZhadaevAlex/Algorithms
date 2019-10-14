#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[] = {5, 8, 7, 3, 0, 9, 1, 2, 4, 6};
int i = 0;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void preOrderTravers(Node *root) {
    if (root) {
        printf("%d", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void printTree(Node* root) {
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

//1. Всегда используем один узел в качестве корня
//2. Строим левое поддерево из n/2 элементов (L)
//3. Строим правое поддерево из n-L-1 элементов
Node* tree(int n) {
    Node *node;
    if (n == 0)
        node = NULL;
    else {
        int value = arr[i++];
        node = (Node*) malloc(sizeof(Node));
        node->data = value;
        int nL = n / 2;
        int nR = n - nL - 1;
        node->left = tree(nL);
        node->right = tree(nR);
    }

    return node;
}

int main(void)
{
    Node* t = tree(10);
    printTree(t);
    printf("\n");

    char str[100];
    printf("Введите последовательность символов: ");
    scanf("%s", str);

    int len = strlen(str);

    int result = 0;

    for (int i = 0; i < len; i++)
    {
        result += str[i];
    }

    printf("%d ", result);
    printf("%c ", result);

    return 0;
}
