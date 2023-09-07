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
int dequeue(Queue *queue, bool *status);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void print_queue(Queue *queue);
void destroy_queue(Queue *queue);


void main(void) {
    bool status = false;
    Queue *q = create_queue();
    enqueue(q, 21);
    enqueue(q, 27);
    print_queue(q);
    int value = peek(q, &status);
    if(status) {
        printf("%i\n", value);
    } else {
        printf("%s\n", "No value to peek");
    }
    int dequeued_value = dequeue(q, &status);
    if(status) {
        printf("%s%i\n", "Dequeue successful value ", dequeued_value);
    } else {
        printf("%s\n", "Queue is empty, no dequeue for now");
    }
    print_queue(q);
    dequeued_value = dequeue(q, &status);
    if(status) {
        printf("%s%i\n", "Dequeue successful value ", dequeued_value);
    } else {
        printf("%s\n", "Queue is empty, no dequeue for now");
    }
    printf("%i\n", q->size);
}

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    printf("%s\n", "Queue Created");
    return q;
}

void print_queue(Queue *queue) {
    if(!is_empty(queue)) {
        struct Node *hook = queue->head;
        while(hook != NULL) {
            printf("%i\n", hook->value);
            hook = hook->next;
        }
    } else {
        printf("%s\n", "Queue is empty, print_queue failed");
    }
}

int peek(Queue *queue, bool *status) {
    *status = false;
    if(!is_empty(queue)) {
        *status = true;
        return queue->head->value;
    }
}

void enqueue(Queue *queue, int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->value = value;
    n->next = NULL;
    if(is_empty(queue)) {
        queue->tail = n;
        queue->head = n;
    } else {
        queue->tail->next = n;
        queue->tail = n;
    }
    queue->size++;
}

bool is_empty(Queue *queue) {
    return (queue->size == 0);
}

int dequeue(Queue *queue, bool *status) {
    if(is_empty(queue)) {
        *status = false;
        return 0;
    }
    *status = true;
    int oldHeadValue = queue->head->value;
    struct Node *oldHead = queue->head;
    if(queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    }else {
        queue->head = queue->head->next;
    }
    free(oldHead);
    queue->size--;
    return oldHeadValue;
}

void destroy_queue(Queue *queue) {
    struct Node *h = queue->head;
    while(h != NULL) {
        struct Node *temp = h;
        h = h->next;
        free(temp);
    }
    free(queue);

}

