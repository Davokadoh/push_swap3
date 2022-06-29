/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <jleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:39 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 13:46:03 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate(char ch, t_stack *stack, int target)
{
	int	target_value;

	target_value = stack->arr[target];
	while (stack->arr[0] != target_value)
	{
		if (target > ((stack->size) / 2 + 1))
			rev_rotate(ch, stack);
		else
		{
			rotate(ch, stack);
		}
	}
}
