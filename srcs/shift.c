/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <jleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:29 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/29 13:45:31 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	shift_left(long int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
}

void	shift_right(long int *arr, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
}
