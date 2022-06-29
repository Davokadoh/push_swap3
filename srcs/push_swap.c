/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <jleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:05 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 13:55:07 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	check_unique(t_stack stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack.size)
	{
		j = i + 1;
		while (j < stack.size)
		{
			if (stack.arr[i] == stack.arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_lengths(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		if (stack.arr[i] > 2147483647 || stack.arr[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	error(t_stack *stack)
{
	if (stack->arr)
		free(stack->arr);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	char	**strs;

	if (argc < 2)
		return (error(&a));
	else if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = copy_strs(argv, argc);
	if (!check_input(strs))
		return (error(&a));
	a.size = count_arr(strs);
	a.arr = strs_to_ints(strs);
	if (check_lengths(a))
		return (error(&a));
	if (check_unique(a))
		return (error(&a));
	sort(&a);
	free(a.arr);
	free_strs(strs);
	return (0);
}
