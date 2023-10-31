#include "binary_trees.h"

/**
 * preorder_traverse - traverse binary tree in pre-order fashion
 * @tree: pointer to the root node of the binary tree to traverse
 * @nodes: pointer to number of nodes with at least 1 child in a binary tree
 *
 * Return: Nothing
 */

void preorder_traverse(const binary_tree_t *tree, size_t *nodes)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL || tree->right != NULL)
		*nodes += 1;

	preorder_traverse(tree->left, nodes);
	preorder_traverse(tree->right, nodes);
}


/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes with at least 1 child in a binary tree
 * or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	preorder_traverse(tree, &nodes);

	return (nodes);
}
