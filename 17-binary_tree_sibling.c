#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node or NULL if node is NULL
 * or the parent is NULL or node has no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		sibling = node->parent->right;
	else if (node->parent->right == node)
		sibling = node->parent->left;

	if (sibling != NULL)
		return (sibling);

	return (NULL);
}
