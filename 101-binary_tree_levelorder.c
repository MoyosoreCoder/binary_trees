#include "binary_trees.h"
/**
 *
 */
size_t height_in_binary(const binary_tree_t *tree)
{
	size_t le = 0;
	size_t re = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			le = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			re = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((le > re) ? le : re);
	}
}
/**
 *
 *
 */
size_t depth_of_binary(link_t **begin_at, const binary_tree_t *tree, size_t level)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 *
 *
 */
void exact_node(linked **begin_at, const binary_tree_t *tree, size_t level)
{
	link_t *memory_ad, *last_at;

	memory_ad = malloc(sizeof(link_t));

	if (memory_ad == NULL)
	{
		return;
	}
	memory_ad->n = level;
	memory_ad->node = tree;

	if (*begin_at == NULL)
	{
		memory_ad->next = NULL;
		*head = memory_ad;
	}
	else
	{
		last_at = *begin_at;
		while (last_at->next != NULL)
		{
			last_at = last_at->next;
		}
		memory_ad->next = NULL;
		last_at->next = memory_ad;
	}
}

/**
 *
 *
 */
void function_recursion(link_t **begin_at, const binary_tree *tree)
{
	size_t num_level = 0;

	if (tree != NULL)
	{
		num_level = depth_of_binary(tree);
		exact_node(begin_at, tree, level);
		function_recursion(begin_at, tree->left);
		function_recursion(begin_at, tree->height);
	}
}
/**
 *
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *begin_at, *last_at;
	size_t at_height = 0; number = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		at_height = height_in_binary(tree);
		begin_at = NULL;
		function_recursion(&begin_at, tree);
		while (number <= at_height)
		{
			last_at = begin_at;
			while (last_at != NULL)
			{
				if (number == last_at->n)
				{
					func(last_at->node->n);
				}
				last_at = last_at->next;
			}
			number++;
		}
		while (begin_at != NULL)
		{
			last_at = begin_at;
			begin_at = begin_at->next;
			free(begin_at);
		}
	}
}
