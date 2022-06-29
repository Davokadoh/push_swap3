/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <jleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:05 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 11:25:37 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	check_ints(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size - 1)
	{
		if (stack.arr[i] > 2147483647 || stack.arr[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static int	error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	char	**strs;

	if (argc < 2)
		return (error());
	else if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = copy_strs(argv, argc);
	if (!check_input(strs))
		return (error());
	a.size = count_arr(strs);
	a.arr = strs_to_ints(strs);
	if (check_ints(a))
		return (error());
	sort(&a);
	free(a.arr);
	free_strs(strs);
	return (0);
}
