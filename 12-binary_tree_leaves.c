#include "binary_trees.h"

/**
 * preorder_traverse - traverse binary tree in pre-order fashion
 * @tree: pointer to the root node of the binary tree to traverse
 * @leaves: pointer to number of leaves of the binary tree
 *
 * Return: Nothing
 */

void preorder_traverse(const binary_tree_t *tree, size_t *leaves)
{
	if (tree == NULL)
		return;

	if (tree->left == NULL && tree->right == NULL)
		*leaves += 1;

	preorder_traverse(tree->left, leaves);
	preorder_traverse(tree->right, leaves);
}


/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: number of leaves in a binary tree or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	preorder_traverse(tree, &leaves);

	return (leaves);
}
