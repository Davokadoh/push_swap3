/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:34:17 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/28 16:36:30 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_stack *stack)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < stack->arr[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}
