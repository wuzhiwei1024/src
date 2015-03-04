#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int ELEMENT_TYPE;
struct queue_record
{
	int capacity;
	int front;
	int rear;
	int size;
	ELEMENT_TYPET *array;
}

int queue_empty(struct queue_record *queue);
int queue_full(struct queue_record *queue);
struct queue_record *create_queue(int max_elements);
void make_empty(struct queue_record *queue);
void enqueue(ELEMENT_TYPE x, struct queue_record *queue);
ELEMENT_TYPE queue_front(struct queue_record *queue);
void dequeue(struct queue_record *queue);
ELEMENT_TYPE front_dequeue(struct queue_record *queue);
