#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_measure, right_measure;

	if (tree == NULL)
		return (0);

	left_measure = binary_tree_size(tree->left);
	right_measure = binary_tree_size(tree->right);

	return (left_measure + right_measure + 1);
}
