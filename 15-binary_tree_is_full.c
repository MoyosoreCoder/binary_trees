#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if binary is full
 * @tree: the pointer to the binary tree elements
 *
 *
 * Return: 1 if full, 0 if if truee is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL))
		return (0);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
