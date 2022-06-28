#include "push_swap.h"

int top(t_stack *stack, int pivot)
{
	int i;

	i = 0;
	while (i <= stack->size / 2)
	{
		if (stack->arr[i] <= pivot)
			return (i);
		i++;
	}
	return (i);
}

int bot(t_stack *stack, int pivot)
{
	int i;

	i = stack->size - 1;
	while (i >= stack->size / 2)
	{
		if (stack->arr[i] <= pivot)
			return (i);
		i--;
	}
	return (i);
}

void	sort3(t_stack *a)
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

void	sort5(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
		return;
	smart_rotate('a', a, get_smallest(a), 0);
	push('b', a, b);
	smart_rotate('a', a, get_smallest(a), 0);
	push('b', a, b);
	sort3(a);
	push('a', b, a);
	push('a', b, a);
}

int	get_pivot(t_stack stack, int chunk_size, int j)
{
	if (stack.size < stack.arr[j * stack.size/ chunk_size])
		return (stack.arr[stack.size - 1]);
	else
		return (stack.arr[j * stack.size/ chunk_size]);
}

void	chunck_to_a(t_stack *a, t_stack *b)
{
	t_stack	sorted;
	int		pivot;
	int		target1;
	int		target2;
	int		i;
	int		j;
	int		chunk_size;

	sorted = copy_stack(a);
	bubble_sort(&sorted);
	if (sorted.size < 120)
		chunk_size = 5;
	else
		chunk_size = 8;
	i = 0;
	j= 0;
	while (a->size > 0)
	{
		if (i % (sorted.size / chunk_size) == 0)
			pivot = get_pivot(sorted, chunk_size, ++j);
		//pivot = sorted.arr[++j * sorted.size / chunk_size];
		target1 = top(a, pivot);
		target2 = bot(a, pivot);
		if (target1 <= a->size - target2 + 1)
			smart_rotate('a', a, target1, 0);
		else
			smart_rotate('a', a, target2, 0);
		push('b', a, b);
		i++;
	}
	free(sorted.arr);
}

void	push_back_to_b(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		{
			smart_rotate('b', b, get_biggest(b), 1);
			push('a', b, a);
		}
}

void sort_max(t_stack *a, t_stack *b)
{
	chunck_to_a(a, b);
	push_back_to_b(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort3(a);
	else if (a->size == 5)
		sort5(a, b);
	else
		sort_max(a, b);
}
