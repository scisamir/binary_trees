#include "binary_trees.h"

/**
 * add_to_queue_end - adds a binary tree to a queue
 * @my_queue: the queue to add the binary tree to
 * @tree: the binary tree to be added
 *
 * Return: Nothing
 */
void add_to_queue_end(queue_t **my_queue, binary_tree_t *tree)
{
	queue_t *new = NULL, *ptr = NULL;

	if (my_queue == NULL || tree == NULL)
		return;

	new = malloc(sizeof(queue_t));
	if (new == NULL)
		return;

	new->memb = tree;
	new->next = NULL;

	if (*my_queue == NULL)
		*my_queue = new;
	else
	{
		ptr = *my_queue;

		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

/**
 * remove_from_queue_front - removes a binary tree from a queue
 * @my_queue: the queue to remove the binary tree from
 *
 * Return: Nothing
 */
void remove_from_queue_front(queue_t **my_queue)
{
	queue_t *temp = NULL;

	if (my_queue == NULL || *my_queue == NULL)
		return;

	temp = *my_queue;
	*my_queue = (*my_queue)->next;
	free(temp);
}


/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *my_queue = NULL;
	binary_tree_t *node = NULL;

	if (tree == NULL || func == NULL)
		return;

	add_to_queue_end(&my_queue, (binary_tree_t *)tree);

	while (my_queue != NULL)
	{
		node = my_queue->memb;
		func(node->n);

		add_to_queue_end(&my_queue, node->left);
		add_to_queue_end(&my_queue, node->right);

		remove_from_queue_front(&my_queue);
	}
}
