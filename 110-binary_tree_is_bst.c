#include "binary_trees.h"

/**
 * binary_tree_is_bst - Binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst - Utility function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum allowed value for a node in the tree
 * @max: Maximum allowed value for a node in the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left = is_bst(tree->left, min, tree->n);
	right = is_bst(tree->right, tree->n, max);

	return (left && right);
}
