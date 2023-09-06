#include "library.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
struct Node {
    int value;
    struct Node *next;
};

typedef struct {
    int size;
    struct Node *head;
    struct Node *tail;
} Queue;

Queue *create_queue();
void enqueue(Queue *queue, int value, bool *status);

void hello(void) {
    Queue *q = create_queue();

    printf("Hello, World!\n");
}

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *queue, int value, bool *status) {
    *status = true;
    struct Node *n = malloc(sizeof(struct Node));
    n->value = value;
    queue->tail->next = n;
    queue->tail = n;
    queue->size++;
}