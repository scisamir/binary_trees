#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 *
 * Return: lowest common ancestor of two nodes or NULL
 * if no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ptr = NULL, *ptr2 = NULL, *lca = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	ptr = first;

	while (ptr != NULL)
	{
		ptr2 = second;

		while (ptr2 != NULL)
		{
			if (ptr == ptr2)
			{
				lca = ptr;
				break;
			}

			ptr2 = ptr2->parent;
		}

		if (lca != NULL)
			break;

		ptr = ptr->parent;
	}

	return ((binary_tree_t *)lca);
}
