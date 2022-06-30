/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:39:20 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/29 17:29:42 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_player
{
	int		horizontal;
	int		vertical;
	t_map	map;

}	t_player;

typedef struct s_errors
{
	int		colcount;
	int		plycount;
	int		extcount;

}	t_errors;

typedef struct s_so_long
{
	t_map		map;
	t_player	myplayer;
	t_errors	maperrors;

	void		*mlx;
	void		*window;

	void		*path;
	void		*wall;
	void		*player;
	void		*collect;
	void		*exitus;

	int			collectible;
	int			colsum;

	int			steps;

	char		*rel_path_path;
	char		*rel_path_wall;
	char		*rel_path_ply;
	char		*rel_path_col;
	char		*rel_path_exi;

	int			img_width;
	int			img_height;
	int			i;
	int			j;

}	t_so_long;

//		initializing the pictures
void	init_img(t_so_long *mygame);
//		setting the player coordinates
void	set_player(int jwidth, int iheight, t_so_long *mygame);
//		etting and counting up the collectibles
void	set_collect(int jwidth, int iheight, t_so_long *mygame);

//		paiting functions
void	paint_wall(int x, int y, t_so_long *wall);
void	paint_path(int x, int y, t_so_long *path);
void	paint_player(int x, int y, t_so_long *playerimg);
void	paint_collect(int x, int y, t_so_long *collect);
void	paint_exit(int x, int y, t_so_long *exitus);

//		for moving the player around
int		player_move(int keycode, t_so_long *mygame);
void	up(t_so_long *mygame);
void	left(t_so_long *mygame);
void	bottom(t_so_long *mygame);
void	right(t_so_long *mygame);

//		for updatiing the map
void	update_map(int x, int y, t_so_long *mypath);
void	current_field(int iheight, int jwidth, t_so_long *mygame);

//		dealing with errors
void	errors(t_so_long *mygame);
int		checkmap_lu(t_so_long *mygame);
int		checkmap_rd(t_so_long *mygame);
int		checkmap_in(t_so_long *mygame);
int		check_min(t_so_long *mygame);
int		check_square(t_so_long *mygame);

//		exit game
int		exit_game(void);

//		counting the collectible
void	count_col(t_so_long *mygame);
void	check_col(t_so_long *mygame);

//		so_long main
int		count_map_unit(char **argv);
void	read_map(t_so_long *mygame, char **argv);
void	map_base(t_so_long *mygame);
void	paintmap(t_so_long *mygame);

#endif
