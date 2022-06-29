/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:44 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 11:08:19 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(t_stack *a)
{
	while (is_sorted(a) == 0)
	{
		if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2])
			rotate('a', a);
		else if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2])
			rev_rotate('a', a);
		else
			swap('a', a);
	}
}

static void	sort5(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
		return ;
	smart_rotate('a', a, get_smallest(a), 0);
	push('b', a, b);
	smart_rotate('a', a, get_smallest(a), 0);
	push('b', a, b);
	sort3(a);
	push('a', b, a);
	push('a', b, a);
}

static void	big_sort(t_stack *a, t_stack *b)
{
	chunk_to_b(a, b);
	while (b->size > 0)
	{
		smart_rotate('b', b, get_biggest(b), 0);
		push('a', b, a);
	}
}

void	sort(t_stack *a)
{
	t_stack	b;

	b = create_empty_stack(a->size);
	if (a->size == 3)
		sort3(a);
	else if (a->size == 5)
		sort5(a, &b);
	else
		big_sort(a, &b);
	free(b.arr);
}
