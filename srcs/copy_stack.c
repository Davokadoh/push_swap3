/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <jleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 13:46:36 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	copy_stack(t_stack *src)
{
	t_stack	new;
	int		i;

	new.size = src->size;
	new.arr = (long int *)malloc(sizeof(long int) * (new.size));
	i = -1;
	while (++i < new.size)
		new.arr[i] = src->arr[i];
	return (new);
}
