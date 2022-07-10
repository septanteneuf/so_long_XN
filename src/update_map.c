/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:42:29 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/10 10:33:51 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//		for updating the map
void	update_map(int x, int y, t_so_long *mypath)
{
	int	y_next;
	int	x_next;

	y_next = mypath->myplayer.vertical;
	x_next = mypath->myplayer.horizontal;
	if (mypath->map.map[y][x] == 'E' || mypath->map.map[y][x] == 'G')
	{
		mypath->map.map[y][x] = 'E';
		mypath->map.map[y_next][x_next] = 'P';
	}
	else
	{
		mypath->map.map[y][x] = '0';
		if (mypath->map.map[y_next][x_next] == 'E')
			mypath->map.map[y_next][x_next] = 'G';
		else
			mypath->map.map[y_next][x_next] = 'P';
	}
}

void	current_field(int x, int y, t_so_long *mypath)
{
	int	y_next;
	int	x_next;

	y_next = mypath->myplayer.vertical;
	x_next = mypath->myplayer.horizontal;
	if (mypath->map.map[y][x] == 'E' || mypath->map.map[y][x] == 'G')
	{
		paint_exit(x, y, mypath);
		paint_player(x_next, y_next, mypath);
		paint_floor(x, y, mypath);
		paint_exit(x, y, mypath);
	}
	else
	{
		paint_floor(x, y, mypath);
		if (mypath->map.map[y_next][x_next] == 'E')
		{
			paint_floor(x, y, mypath);
			paint_exit(x, y, mypath);
		}
		else
			paint_player(x_next, y_next, mypath);
	}
}
