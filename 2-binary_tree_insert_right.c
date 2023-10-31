#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL, *parent_right = NULL;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
		parent_right = parent->right;

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = parent_right;

	parent->right = new;
	if (new->right != NULL)
		new->right->parent = new;

	return (new);
}
