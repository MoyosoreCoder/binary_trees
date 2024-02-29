#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *memory_pointer = malloc(sizeof(binary_tree_t));

	if (memory_pointer == NULL)
		return (NULL);

	memory_pointer->n = value;
	memory_pointer->parent = parent;
	memory_pointer->left = NULL;
	memory_pointer->right = NULL;

	return (memory_pointer);
}
