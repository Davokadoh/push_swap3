/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <jleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:01:35 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 11:43:34 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	top(t_stack *stack, int pivot)
{
	int	i;

	i = 0;
	while (i <= stack->size / 2)
	{
		if (stack->arr[i] <= pivot)
			return (i);
		i++;
	}
	return (i);
}

static int	bot(t_stack *stack, int pivot)
{
	int	i;

	i = stack->size - 1;
	while (i >= stack->size / 2)
	{
		if (stack->arr[i] <= pivot)
			return (i);
		i--;
	}
	return (i);
}

static int	get_pivot(t_stack stack, int chunk_size, int j)
{
	if (j >= chunk_size)
		return (stack.arr[stack.size - 1]);
	else
		return (stack.arr[j * stack.size / chunk_size]);
}

static void	get_target(t_stack *a, int pivot)
{
	int	target1;
	int	target2;

	target1 = top(a, pivot);
	target2 = bot(a, pivot);
	if (target1 < a->size - target2)
		smart_rotate('a', a, target1, 1);
	else
		smart_rotate('a', a, target2, 1);
}

void	chunk_to_b(t_stack *a, t_stack *b)
{
	t_stack	sorted;
	int		i;
	int		j;
	int		pivot;
	int		chunk_size;

	sorted = copy_stack(a);
	bubble_sort(&sorted);
	if (sorted.size <= 100)
		chunk_size = 6;
	else
		chunk_size = 11;
	i = 0;
	j = 0;
	while (a->size > 0)
	{
		if (i % (sorted.size / chunk_size) == 0)
			pivot = get_pivot(sorted, chunk_size, ++j);
		get_target(a, pivot);
		push('b', a, b);
		//if (b->arr[0] < b->arr[1])
		//	swap('b', b);
		i++;
	}
	free(sorted.arr);
}
