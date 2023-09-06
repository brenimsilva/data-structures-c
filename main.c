#include <stdbool.h>
#include <stdlib.h>
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
void enqueue(Queue *queue, int value);
bool is_empty(Queue *queue);

void main(void) {
    bool status = false;
    Queue *q = create_queue();
    enqueue(q, 21);
    printf("%i\n", q->size);
    printf("Hello, World!\n");
}

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *queue, int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->value = value;
    n->next = NULL;
    if(is_empty(queue)) {
        queue->head = n;
        queue->tail = n;
    } else {
        queue->tail->next = n;
        queue->tail = n;
    }
    queue->size++;
};
//void enqueue(Queue *queue, int value, bool status) {
//    status = true;
//    struct Node *n = malloc(sizeof(struct Node));
//    n->value = value;
//    queue->tail->next = n;
//    queue->tail = n;
//    queue->size++;
//}

bool is_empty(Queue *queue) {
    return (queue->size == 0);
}