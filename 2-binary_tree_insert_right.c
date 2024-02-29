#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *another_pointer;

	if (parent == NULL)
		return (NULL);

	another_pointer = malloc(sizeof(binary_tree_t));
	if (another_pointer == NULL)
		return (NULL);

	another_pointer->n = value;
	another_pointer->parent = parent;
	another_pointer->left = NULL;
	another_pointer->right = NULL;

	if (parent->right != NULL)
	{
		another_pointer->right = parent->right;
		another_pointer->right->parent = another_pointer;
	}

	parent->right = another_pointer;
	return (another_pointer);
}
