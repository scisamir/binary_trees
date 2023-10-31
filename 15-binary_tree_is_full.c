#include "binary_trees.h"

/**
 * preorder_traverse - traverse binary tree in pre-order fashion
 * @tree: pointer to the root node of the binary tree to traverse
 * @nodes: pointer to number of nodes with exactly 1 child in a binary tree
 *
 * Return: Nothing
 */

void preorder_traverse(const binary_tree_t *tree, int *nodes)
{
	if (tree == NULL)
		return;

	if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL))
		*nodes += 1;

	preorder_traverse(tree->left, nodes);
	preorder_traverse(tree->right, nodes);
}


/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if it's full otherwise 0 if it's not full or tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int nodes = 0;

	if (tree == NULL)
		return (0);

	preorder_traverse(tree, &nodes);

	if (nodes > 0)
		return (0);

	return (1);
}
