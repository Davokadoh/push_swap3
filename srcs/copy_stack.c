/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/28 16:33:57 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	copy_stack(t_stack *src)
{
	t_stack	new;
	int		i;

	new.size = src->size;
	new.arr = (int *)malloc(sizeof(int) * (new.size));
	i = -1;
	while (++i < new.size)
		new.arr[i] = src->arr[i];
	return (new);
}
