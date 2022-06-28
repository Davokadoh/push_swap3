/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:34:00 by jleroux           #+#    #+#             */
/*   Updated: 2022/06/28 16:38:50 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copy_strs(char **strs, int size)
{
	char	**new_strs;
	int		i;

	new_strs = (char **)malloc(sizeof(char *) * (size));
	i = 1;
	while (i < size)
	{
		new_strs[i - 1] = strdup(strs[i]);
		i++;
	}
	new_strs[i - 1] = NULL;
	return (new_strs);
}
