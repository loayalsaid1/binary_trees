#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct q_node {
	int val;
	struct q_node *next;
} q_node;

typedef struct Queue {
	q_node *head;
	q_node *tail;
	int size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);


int main(void)
{
	Queue *queue = create_queue();

	if (is_empty(queue)) printf("It's empty\n");

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);

	if (!is_empty(queue)) printf("It's not empty\n");

	bool status;
	printf("%d\n", peek(queue, &status));
	printf("%d\n", dequeue(queue, &status));
	printf("%d\n", dequeue(queue, &status));
	printf("%d\n", dequeue(queue, &status));

	destroy_queue(queue);

	return (0);
}



Queue *create_queue()
{
	Queue *queue = malloc(sizeof(Queue));
	if (queue == NULL)
		return (NULL);

	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;

	return (queue);
}



int size(Queue *queue)
{
	if (queue == NULL)
		return (0);

	return (queue->size);
}


bool is_empty(Queue *queue)
{
	return (queue->size == 0);
}


int peek(Queue *queue, bool *status)
{
	if (is_empty(queue))
	{
		*status = false;
		return (0);
	}

	*status = true;
	return (queue->head->val);
}


void enqueue(Queue *queue, int value)
{
	q_node *node;

	if (queue == NULL)
		return;

	/*create a node and feed it*/
	node = malloc(sizeof(q_node));
	if (node == NULL)
		return;
	node->next = NULL;
	node->val = value;

	/*Put it in the queue*/
	if (is_empty(queue))
	{
		queue->head = queue->tail = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}

	queue->size++;
}

int dequeue(Queue *queue, bool *status)
{
	q_node *head_node;
	int value;

	if (is_empty(queue))
	{
		*status = false;
		return (0);
	}

	head_node = queue->head;
	*status = true;

	if (size(queue) == 1)
		queue->tail = NULL;
	queue->head = head_node->next;
	queue->size--;

	value = head_node->val;
	free(head_node);


	return (value);
}


void destroy_queue(Queue *queue)
{
	q_node *curr, *temp;

	if (queue == NULL || is_empty(queue))
		return;

	curr = queue->head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	
	free(queue);
}
