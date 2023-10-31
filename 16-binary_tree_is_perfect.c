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

	left_height = compute_tree_height(tree->left);
	right_height = compute_tree_height(tree->right);

	return (left_height - right_height);
}


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

	preorder_traverse(tree, &nodes);

	if (nodes > 0)
		return (0);

	return (1);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if it's perfect otherwise 0 if it's not perfect or tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((binary_tree_balance(tree) == 0) && binary_tree_is_full(tree))
		return (1);

	return (0);
}
