/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:40:00 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 18:13:20 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//		initializing the pictures
void	init_img(t_so_long *mygame)
{
	mygame->rel_path_floor = "./img/floor.xpm";
	mygame->floor = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_floor,
			&mygame->i, &mygame->j);
	mygame->rel_path_wall = "./img/wall.xpm";
	mygame->wall = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_wall,
			&mygame->i, &mygame->j);
	mygame->rel_path_ply = "./img/player1.xpm";
	mygame->player = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_ply,
			&mygame->i, &mygame->j);
	mygame->rel_path_col = "./img/collect.xpm";
	mygame->collect = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_col,
			&mygame->i, &mygame->j);
	mygame->rel_path_exi = "./img/exit.xpm";
	mygame->exitus = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_exi,
			&mygame->i, &mygame->j);
}

//		setting the player coordinates
void	set_player(int jwidth, int iheight, t_so_long *mygame)
{
	mygame->myplayer.horizontal = jwidth;
	mygame->myplayer.vertical = iheight;
	paint_player(jwidth, iheight, mygame);
}

//		setting and counting up the collectibles
void	set_collect(int jwidth, int iheight, t_so_long *mygame)
{
	mygame->colsum++;
	mygame->collectible++;
	paint_collect(jwidth, iheight, mygame);
}
