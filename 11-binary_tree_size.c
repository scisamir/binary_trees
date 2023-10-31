#include "binary_trees.h"

/**
 * inorder_traverse - goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @size: pointer to size of a binary tree
 *
 * Return: Nothing
 */

void inorder_traverse(const binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
		return;

	inorder_traverse(tree->left, size);
	*size += 1;
	inorder_traverse(tree->right, size);
}


/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of a binary tree or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	inorder_traverse(tree, &size);

	return (size);
}
