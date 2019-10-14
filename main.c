#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char
//#define SIZE 100

//Реализация структуры через массив
//T Stack[SIZE];
//int ind = -1;

//void push(char value) {
//    if (ind < SIZE)
//        Stack[++ind] = value;
//    else
//        printf("Stack overflow");
//}

//T pop() {
//    if (ind != -1)
//        return Stack[ind--];
//    else {
//        printf("Stack is empty");
//        return -1;
//    }
//}

//Реализация стека через односвязный список
typedef int boolean;
#define true 1
#define false 0;

typedef struct Node {
    T data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

boolean push(Stack *st, T value) {
    Node *temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL)
        return false;

    temp->data = value;
    temp->next = st->head;
    st->head = temp;
    st->size++;
    return true;
}

T pop(Stack *st) {
    if (st->size == 0)
        return -1;

    Node *temp = st->head;
    T result = temp->data;
    st->head = st->head->next;
    st->size--;
    free(temp);
    return result;
}

T peek(Stack *st) {
    if (st->size == 0)
        return -1;

    return st->head->data;
}

//Печать стека
void printStack(Stack st) {
    Node *current = st.head;

    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
}

//Реализация очереди через двусвязный список
typedef struct NodeTwo {
    T data;
    struct NodeTwo *next;
    struct NodeTwo *prev;

} NodeTwo;

typedef struct {
    NodeTwo *head;
    NodeTwo *tail;
    int size;
} Queue;

boolean Enqueue(Queue *que, T value) {
    NodeTwo *temp = (NodeTwo*) malloc(sizeof(NodeTwo));
    if (temp == NULL)
        return false;

    temp->data = value;
    temp->next = que->head;
    temp->prev = NULL;

    if (que->head != NULL)
        que->head->prev = temp;
    else
        que->tail = temp;

    que->head = temp;

    que->size++;

    return true;
}

T Dequeue(Queue *que) {
    if (que->size == 0)
        return -1;

    NodeTwo *temp = que->tail;
    T result = temp->data;

    que->tail = que->tail->prev;

    if (que->size > 1)
        que->tail->next = NULL;
    else
        que->head = NULL;

    free(temp);

    que->size--;

    return result;
}

//Печать очереди
void printQueue(Queue que) {
    NodeTwo *current = que.tail;

    while (current != NULL) {
        printf("%c", current->data);
        current = current->prev;
    }
}

//Функция проверки правильности скобок
boolean checkBrace(char* str) {
    Stack stack;

    stack.size = 0;
    stack.head = NULL;

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                push(&stack, str[i]);
        else if (str[i] == ')') {
            if (stack.size == 0 || pop(&stack) != '(')
                return false;
        }
        else if (str[i] == ']') {
            if (stack.size == 0 || pop(&stack) != '[')
                return false;
        }
        else if (str[i] == '}') {
            if (stack.size == 0 || pop(&stack) != '{')
                return false;
        }
        else
            continue;
    }

    if (stack.size != 0)
        return false;

    return true;
}

//Копирование односвязного списка
void copyLinkedList(Stack *st, Stack *stCopy) {
    stCopy->size = 0;
    stCopy->size = 0;
    stCopy->head = NULL;

    Stack stTmp;
    stTmp.size = 0;
    stTmp.head = NULL;

    Node *current = st->head;

    while (stTmp.size != st->size) {
        push(&stTmp, current->data);
        current = current->next;
    }

    while (stTmp.size > 0)
        push(stCopy, pop(&stTmp));
}

int main(void)
{
    //1. Написать программу, которая определяет,
    //является ли введенная скобочная последовательность правильной.
    //Примеры правильных скобочных выражений:
    //(), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
    printf("Задание 1. Проверка правильности скобок\n");

    char str[100];
    printf("Введите скобочное выражение:\n");
    scanf("%s", str);

    printf("Последовательность %s\n", checkBrace(str) ? "правильная" : "неправильная");

    printf("\n");

    //2. *Создать функцию, копирующую односвязный список
    //(то есть создает в памяти копию односвязного списка, без удаления первого списка).
    printf("Задание 2. Копирование односвязного списка\n");

    Stack stack;
    stack.size = 0;
    stack.head = NULL;

    push(&stack, 'a');
    push(&stack, 'b');
    push(&stack, 'c');

    Stack stackCopy;
    stackCopy.size = 0;
    stackCopy.head = NULL;

    copyLinkedList(&stack, &stackCopy);

    printf("Исходный односвязный список: ");
    printStack(stack);
    printf("\n");
    printf("Копия односвязного списка: ");
    printStack(stackCopy);

    printf("\n\n");

    //3. *Реализовать очередь на основе двусвязного списка.
    printf("Задание 3. Реализация очереди\n");

    Queue q;
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;

    Enqueue(&q, 'a');
    Enqueue(&q, 'b');
    Enqueue(&q, 'c');
    Enqueue(&q, 'd');
    Enqueue(&q, 'e');

    printQueue(q);

    printf("\n");
    return 0;
}

