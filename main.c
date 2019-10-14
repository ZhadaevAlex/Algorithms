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

//Прямой обход
void preOrderTravers(Node *root) {
    if (root) {
        printf("%d", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

//Симметричный обход
void inOrderTravers(Node *root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d", root->data);
        inOrderTravers(root->right);
    }
}

//Обратный обход
void postOrderTravers(Node *root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d", root->data);

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

int hashAcsii(char* str) {
    int result = 0;

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        result += str[i];
    }

    return result;
}

int main(void)
{
    Node* t = tree(10);
    printTree(t);
    printf("\n");

    //1. Реализовать простейшую хэш-функцию.
    //На вход функции подается строка, на выходе сумма кодов символов.
    printf("Задание 1\n");
    char str[100];
    printf("Введите последовательность символов: ");
    scanf("%s", str);

    printf("Хэш-код: %d\n", hashAcsii(str));

    printf("\n");

    //2. Реализовать двоичное дерево поиска
    //а) Добавить обход дерева различными способами;
    //б) Реализовать поиск в двоичном дереве поиска;
    printf("Задание 2\n");
    printf("Прямой обход: ");
    preOrderTravers(t);
    printf("\n");
    printf("Симмеричный обход: ");
    inOrderTravers(t);
    printf("\n");
    printf("Обратный обход: ");
    postOrderTravers(t);
    printf("\n");

    return 0;
}
