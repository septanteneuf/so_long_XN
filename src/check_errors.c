/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:38:58 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 18:11:43 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkmap_lu(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		if (mygame->map.map[height][width] != '1')
			return (-1);
		height++;
	}
	height = 0;
	width = 0;
	while (width < mygame->img_width)
	{
		if (mygame->map.map[height][width] != '1')
			return (-1);
		width++;
	}
	return (0);
}

int	checkmap_rd(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = mygame->img_width - 1;
	while (height < mygame->img_height)
	{
		if (mygame->map.map[height][width] != '1')
			return (-1);
		height++;
	}
	height = mygame->img_height - 1;
	width = 0;
	while (width < mygame->img_width)
	{
		if (mygame->map.map[height][width] != '1')
			return (-1);
		width++;
	}
	return (0);
}

int	checkmap_in(t_so_long *mygame)
{
	int		height;
	int		width;
	char	c;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		while (width < mygame->img_width)
		{
			c = mygame->map.map[height][width];
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (-1);
			width++;
		}
		height++;
		width = 0;
	}
	return (0);
}

int	check_min(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		while (width < mygame->img_width)
		{
			if (mygame->map.map[height][width] == 'P')
				mygame->maperrors.plycount++;
			else if (mygame->map.map[height][width] == 'C')
				mygame->maperrors.colcount++;
			else if (mygame->map.map[height][width] == 'E')
				mygame->maperrors.extcount++;
			width++;
		}
		height++;
		width = 0;
	}
	if (mygame->maperrors.plycount < 1 || mygame->maperrors.colcount < 1
		|| mygame->maperrors.extcount < 1)
		return (-1);
	else
		return (0);
}

void	errors(t_so_long *mygame)
{
	if (checkmap_lu(mygame) == -1 || checkmap_rd(mygame) == -1
		|| checkmap_in(mygame) == -1 || check_min(mygame) == -1
		|| check_square(mygame) == -1)
	{
		ft_printf("Error\n");
		ft_printf("It seems there is a problem with your map \n");
		exit (0);
	}
}
