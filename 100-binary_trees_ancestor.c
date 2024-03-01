#include "binary_trees.h"
/**
 * binary_trees_ancestor - function that finds the lowest
 * common ancestor of two nodes
 * @first: first pointer to binary tree
 * @second: second pointer to binary tree
 *
 * Return: no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *pointer_one, *pointer_two;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	pointer_one = first->parent, pointer_two = second->parent;
	if (first == pointer_two || !pointer_one ||
			(!pointer_one->parent && pointer_two))
		return (binary_trees_ancestor(first, pointer_two));
	else if (pointer_one == second || !pointer_two ||
			(!pointer_two->parent && pointer_one))
		return (binary_trees_ancestor(pointer_one, second));
	return (binary_trees_ancestor(pointer_one, pointer_two));
}
