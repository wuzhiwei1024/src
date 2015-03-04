#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_empty(struct queue_record *queue)
{
	return queue->size == 0;
}

int queue_full(struct queue_record *queue)
{
	return queue->size == queue->capacity;
}

struct queue_record *create_queue(int max_elements)
{
	struct queue_record *queue;

	queue = malloc(sizeof(struct queue_record));
	if (NULL == queue) {
		printf("error:out of space!\n");
		return NULL;
	}

	queue->array = malloc(sizeof(ELEMENT_TYPE) * max_elements);
	if (NULL == queue->array) {
		printf("error:out of space!\n");
		return NULL;
	}

	queue->capacity = max_elements;
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
}

void make_empty(struct queue_record *queue)
{
	if (queue == NULL || queue->array == NULL) {
		printf("error:Null pointer!\n");
		return;
	}

	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
}	

void enqueue(ELEMENT_TYPE x, struct queue_record *queue)
{
	if (queue_full(queue)) {
		printf("error:queue is full!\n");
		return;
	}

	queue->array[++queue->rear] = x;
	queue->size++;
}

ELEMENT_TYPE queue_front(struct queue_record *queue)
{
	return queue->array[queue->front];
}

void dequeue(struct queue_record *queue)
{
	if (queue->front++ == queue->capacity)
		queue->front = 0;
}

ELEMENT_TYPE front_dequeue(struct queue_record *queue)
{
	ELEMENT_TYPE element;

	if (queue == NULL || queue->array == NULL) {
		printf("error:Null pointer!\n");
		return;
	}

	element = queue->array[queue->front++];
	if (queue->front == queue->capacity)
		queue->front = 0;

	return element;
}
