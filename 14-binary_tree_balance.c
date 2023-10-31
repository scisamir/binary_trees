#include "binary_trees.h"

/**
 * compute_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of binary tree or 0 if tree is NULL
 */

int compute_tree_height(const binary_tree_t *tree)
{
	int height = 0, ptr_left = 0, ptr_right = 0;

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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of a binary tree or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = compute_tree_height(tree->left);
	right_height = compute_tree_height(tree->right);

	return (left_height - right_height);
}
