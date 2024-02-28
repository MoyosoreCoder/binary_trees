#include "binary_trees.h"
/**
 * calculate_b_tree_height - the function that measures the height
 * @tree: the pointer to binary_tree_t
 *
 * Return: the height of the binary tree, 0 if tree is NULL
 */
size_t calculate_b_tree_height(const binary_tree_t *tree)
{
	size_t left_handed = 0, right_handed = 0;

	if (tree == NULL)
		return (0);

	left_handed = tree->left ? 1 + calculate_b_tree_height(tree->left) : 1;
	right_handed = tree->right ? 1 + calculate_b_tree_height(tree->right) : 1;


	return ((left_handed > right_handed) ? left_handed : right_handed);
}

/**
 * binary_tree_balance - function that self balance
 * @tree: pointer to the binary tree contents
 *
 * Return: Balnced factor or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0, answer_solve = 0;

	if (tree)
	{
		left = ((int)calculate_b_tree_height(tree->left));
		right = ((int)calculate_b_tree_height(tree->right));
		answer_solve = left - right;
	}
	return (answer_solve);
}
