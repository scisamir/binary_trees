#include "binary_trees.h"

/**
 * compute_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of binary tree or 0 if tree is NULL
 */

size_t compute_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, ptr_left = 0, ptr_right = 0;

	if (tree == NULL)
		return (0);

	ptr_left = compute_tree_height(tree->left);
	ptr_right = compute_tree_height(tree->right);

	if (ptr_left > ptr_right)
		height = ptr_left;
	else
		height = ptr_right;

	return (1 + height);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of binary tree minus 1 or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	height = compute_tree_height(tree);
	height -= 1;

	return (height);
}
