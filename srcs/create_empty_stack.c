/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_empty_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:40:20 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 10:50:08 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_empty_stack(int size)
{
	t_stack	stack;

	stack.arr = (int *)malloc(sizeof(int) * size);
	stack.size = 0;
	return (stack);
}
