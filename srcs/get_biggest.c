/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:58:24 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 10:58:26 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest(t_stack *stack)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > stack->arr[biggest])
			biggest = i;
		i++;
	}
	return (biggest);
}
