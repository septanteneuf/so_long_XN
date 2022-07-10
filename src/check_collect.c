/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:37:49 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 17:17:06 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//		counting the collectible
void	count_col(t_so_long *mygame)
{
	mygame->collectible--;
}

void	check_col(t_so_long *mygame)
{
	if (mygame->collectible == 0)
	{
		exit (0);
	}
}
