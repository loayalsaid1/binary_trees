#include "binary_trees.h"


/**
 * binary_tree_levelorder - Traverse a tree with the breadth first approach
 * @tree: The root of the tree
 * @func: Function to implement on each value in the tree nodes
 * Return: Void
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *current;
	Queue *queue;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(Queue));
	if (queue == NULL)
		return;
	queue->head = queue->tail = NULL;
	queue->size = 0;


	enqueue(queue, (binary_tree_t *)tree);

	while (queue->size > 0)
	{
		current = dequeue(queue);
		func(current->n);

		if (current->left)
			enqueue(queue, current->left);
		if (current->right)
			enqueue(queue, current->right);
	}

	destroy_queue(queue);
	free(queue);
}


/**
 * enqueue - Add an element to the queue
 * @queue: The queue
 * @tree: The node to feed the queue node
 * Return: None
*/
void enqueue(Queue *queue, binary_tree_t *tree)
{
	q_node *node;

	if (queue == NULL)
		return;

	/*create a node and feed it*/
	node = malloc(sizeof(q_node));
	if (node == NULL)
		return;
	node->next = NULL;
	node->tree = tree;

	/*Put it in the queue*/
	if (queue->size == 0)
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

/**
 * dequeue - return the last element of a queue
 * @queue: The queue
 * Return: The node
*/
binary_tree_t *dequeue(Queue *queue)
{
	q_node *head_node;
	binary_tree_t *t_node;

	if (queue->size == 0)
	{
		return (NULL);
	}

	head_node = queue->head;

	if (queue->size == 1)
		queue->tail = NULL;
	queue->head = head_node->next;
	queue->size--;

	t_node = head_node->tree;
	free(head_node);


	return (t_node);
}

/**
 * destroy_queue - Free a queue
 * @queue: The queue
 * Return: Void
*/
void destroy_queue(Queue *queue)
{
	q_node *curr, *temp;

	if (queue == NULL || queue->size == 0)
		return;

	curr = queue->head;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(curr);
	free(queue);
}
