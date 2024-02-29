#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts left-child node of another node
 * @parent: the parent in the binary tree
 * @value: the value to be used
 *
 * Return: the new memory addrress in the binary tree
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_add;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_add = binary_tree_node(parent, value);
	if (new_add == NULL)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		new_add->left = parent->left;
		parent->left->parent = new_add;
	}
	parent->left = new_add;
	return (new_add);
}
