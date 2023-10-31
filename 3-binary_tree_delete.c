#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *tree_left = NULL, *tree_right = NULL;

	if (tree == NULL)
		return;

	tree_left = tree->left;
	tree_right = tree->right;

	free(tree);
	tree = NULL;

	binary_tree_delete(tree_left);
	binary_tree_delete(tree_right);
}
