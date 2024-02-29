#include "binary_trees.h"

unsigned char true_leaf(const binary_tree_t *node);
size_t calculate_depth(const binary_tree_t *tree);
const binary_tree_t *search_leaf(const binary_tree_t *tree);
int helper_recursive(const binary_tree_t *tree,
size_t depth_pos, size_t first_level);
int binary_tree_is_perfect(const binary_tree_t *tree);
/**
 * true_leaf - function that checks if node points to left or righ
 * @node: every child of the root
 *
 * Return: true or false
 */
unsigned char true_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
/**
 * calculate_depth - function that calculate the depth
 * @tree: pointer to the first element in binary tree
 *
 * Return: depth of the tree
 */
size_t calculate_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + calculate_depth(tree->parent) : 0);
}
/**
 * search_leaf - searches for leaf if true
 * @tree: the pointer to the first node
 *
 * Return: the first node with leaf
 */
const binary_tree_t *search_leaf(const binary_tree_t *tree)
{
	if (true_leaf(tree) == 1)
		return (tree);
	return (tree->left ? search_leaf(tree->left) : search_leaf(tree->right));
}
/**
 * helper_recursive - checks if leaf is present
 * @tree: pointer to the binary tree
 * @depth_pos: the depth position from node to leaf
 * @first_level: from the beginning
 *
 * Return: If the tree is perfect, 1, otherwise 0
 */
int helper_recursive(const binary_tree_t *tree,
		size_t depth_pos, size_t first_level)
{
	if (true_leaf(tree))
		return (first_level == depth_pos ? 1 : 0);

	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (helper_recursive(tree->left, depth_pos, first_level + 1) &&
			helper_recursive(tree->right, depth_pos, first_level + 1));
}
/**
 * binary_tree_is_perfect - binary tree that checks if it is perfect
 * @tree: a pointer to the binary tree
 *
 * Return: NULL if tree is empty or 0, 1 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (helper_recursive(tree, calculate_depth(search_leaf(tree)), 0));
}
