/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:40:15 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 18:05:51 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//		paiting functions
void	paint_floor(int x, int y, t_so_long *myfloor)
{
	mlx_put_image_to_window(myfloor->mlx, myfloor->window, myfloor->floor,
		x * 100, y * 100);
}

void	paint_wall(int x, int y, t_so_long *mywall)
{
	mlx_put_image_to_window(mywall->mlx, mywall->window, mywall->wall,
		x * 100, y * 100);
}

void	paint_player(int x, int y, t_so_long *myplayerimg)
{
	mlx_put_image_to_window(myplayerimg->mlx, myplayerimg->window,
		myplayerimg->player, x * 100, y * 100);
}

void	paint_collect(int x, int y, t_so_long *mycollect)
{
	mlx_put_image_to_window(mycollect->mlx, mycollect->window,
		mycollect->collect, x * 100, y * 100);
}

void	paint_exit(int x, int y, t_so_long *myexitus)
{
	mlx_put_image_to_window(myexitus->mlx, myexitus->window, myexitus->exitus,
		x * 100, y * 100);
}
