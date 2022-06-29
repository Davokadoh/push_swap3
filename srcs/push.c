/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:58:41 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 10:58:42 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(char ch, t_stack *src, t_stack *dst)
{
	int	tmp;

	tmp = src->arr[0];
	shift_left(src->arr, src->size);
	src->size--;
	dst->size++;
	shift_right(dst->arr, dst->size);
	dst->arr[0] = tmp;
	write(1, "p", 1);
	write(1, &ch, 1);
	write(1, "\n", 1);
}
