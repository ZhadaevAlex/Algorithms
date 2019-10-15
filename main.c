#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[] = {5, 8, 7, 3, 0, 9, 1, 2, 4, 6};

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
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

Node* getNode(int value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->data = value;
    tmp->left = tmp->right = NULL;
    return tmp;
}

void insertNode(Node** tree, int value) {
    Node* tmp = NULL;
    tmp = *tree;
    if (*tree == NULL) {
        *tree = getNode(value);
        return;
    }
    else if (value > tmp->data)
        insertNode(&tmp->right, value);
    else if (value < tmp->data)
        insertNode(&tmp->left, value);
    else tmp->data = value;
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

Node* searchBinary(Node* root, int value) {
    Node* result = NULL;

    if (root == NULL) {
        return NULL;
    }
    else {
        if (value > root->data)
            result = searchBinary(root->right, value);
        else if (value < root->data)
            result = searchBinary(root->left, value);
        else if (value == root->data)
            result = root;
    }

    return result;
}

int main(void)
{
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

    //Строим дерево
    Node* tree = NULL;

    for(int i = 0; i < 10; i++) {
        insertNode(&tree, arr[i]);
    }

    printf("Скобочная запись дерева: ");
    printTree(tree);
    printf("\n");
    printf("Прямой обход: ");
    preOrderTravers(tree);
    printf("\n");
    printf("Симмеричный обход: ");
    inOrderTravers(tree);
    printf("\n");
    printf("Обратный обход: ");
    postOrderTravers(tree);
    printf("\n");

    //Поиск
    int a;
    printf("Введите число для поиска: ");
    scanf("%d", &a);
    Node *node = searchBinary(tree, a);
    if (node == NULL)
        printf("Искомое значение не найдено\n");
    else {
        printf("Значение: %d\n", node->data);
        printf("Левый узел: ");
        if (node->left != NULL)
            printf("%d\n", node->left->data);
        else
            printf("%s\n", "NULL");
        printf("Правый узел: ");
        if (node->right != NULL)
            printf("%d\n", node->right->data);
        else
            printf("%s\n", "NULL");
    }

    return 0;
}
