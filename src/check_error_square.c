/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:39:05 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 18:11:44 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//	check if there is a closed square
int	check_square(t_so_long *mygame)
{
	int	index;
	int	first_lwidth;

	first_lwidth = ft_strlen(mygame->map.map[0]);
	index = 1;
	while (index < mygame->img_height)
	{
		if ((int)ft_strlen(mygame->map.map[index]) != first_lwidth)
			return (-1);
		index++;
	}
	return (0);
}
