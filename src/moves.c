/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:40:07 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/29 17:39:00 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//		for moving the player around
void	up(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight - 1][jwidth] == '0'
		|| mygame->map.map[iheight - 1][jwidth] == 'C')
	{
		if (mygame->map.map[iheight - 1][jwidth] == 'C')
			count_col(mygame);
		mygame->myplayer.vertical--;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
	else if (mygame->map.map[iheight - 1][jwidth] == 'E')
	{
		mygame->myplayer.vertical--;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		check_col(mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
}

void	left(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight][jwidth - 1] == '0'
		|| mygame->map.map[iheight][jwidth - 1] == 'C')
	{
		if (mygame->map.map[iheight][jwidth - 1] == 'C')
			count_col(mygame);
		mygame->myplayer.horizontal--;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
	else if (mygame->map.map[iheight][jwidth - 1] == 'E')
	{
		mygame->myplayer.horizontal--;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		check_col(mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
}

void	bottom(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight + 1][jwidth] == '0'
		|| mygame->map.map[iheight + 1][jwidth] == 'C')
	{
		if (mygame->map.map[iheight + 1][jwidth] == 'C')
			count_col(mygame);
		mygame->myplayer.vertical++;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
	else if (mygame->map.map[iheight + 1][jwidth] == 'E')
	{
		mygame->myplayer.vertical++;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		check_col(mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
}

void	right(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = mygame->myplayer.vertical;
	jwidth = mygame->myplayer.horizontal;
	if (mygame->map.map[iheight][jwidth + 1] == '0'
		|| mygame->map.map[iheight][jwidth + 1] == 'C')
	{
		if (mygame->map.map[iheight][jwidth + 1] == 'C')
			count_col(mygame);
		mygame->myplayer.horizontal++;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
	else if (mygame->map.map[iheight][jwidth + 1] == 'E')
	{
		mygame->myplayer.horizontal++;
		update_map(jwidth, iheight, mygame);
		current_field(jwidth, iheight, mygame);
		check_col(mygame);
		mygame->steps++;
		ft_printf("You made %d moves\n", mygame->steps);
	}
}

int	player_move(int keycode, t_so_long *mygame)
{
	if (keycode == 13 || keycode == 126)
		up(mygame);
	if (keycode == 0 || keycode == 123)
		left(mygame);
	if (keycode == 1 || keycode == 125)
		bottom(mygame);
	if (keycode == 2 || keycode == 124)
		right(mygame);
	if (keycode == 53)
		exit_game();
	return (0);
}
