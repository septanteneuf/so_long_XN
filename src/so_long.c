/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:40:23 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/08 18:04:45 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_map_unit(char **argv)
{
	int		fd_nbr;
	int		line_nbr;
	char	*str;

	fd_nbr = open(argv[1], O_RDONLY);
	line_nbr = 0;
	while (1)
	{
		str = get_next_line(fd_nbr);
		if (!str)
			break ;
		free (str);
		line_nbr++;
	}
	close(fd_nbr);
	return (line_nbr);
}

void	read_map(t_so_long *mygame, char **argv)
{
	int		fd_nbr;
	int		line_nbr;
	char	*str;

	line_nbr = count_map_unit(argv);
	fd_nbr = open(argv[1], O_RDONLY);
	mygame->map.map = (char **)malloc(line_nbr * sizeof(char *));
	line_nbr = 0;
	while (1)
	{
		str = get_next_line(fd_nbr);
		if (!str)
			break ;
		mygame->map.map[line_nbr] = str;
		line_nbr++;
	}
	close(fd_nbr);
	mygame->img_height = line_nbr;
	mygame->img_width = ft_strlen(mygame->map.map[0]);
}

void	map_base(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		while (width < mygame->img_width)
		{
			paint_floor(width, height, mygame);
			width++;
		}
		height++;
		width = 0;
	}
}

void	paint_map(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		while (width < mygame->img_width)
		{
			if (mygame->map.map[height][width] == '1')
				paint_wall(width, height, mygame);
			else if (mygame->map.map[height][width] == 'P')
				set_player(width, height, mygame);
			else if (mygame->map.map[height][width] == 'C')
				set_collect(width, height, mygame);
			else if (mygame->map.map[height][width] == 'E')
				paint_exit(width, height, mygame);
			width++;
		}
		height++;
		width = 0;
	}
}

int	main(int argc, char **argv)
{
	t_so_long	mygame;

	if (argc != 2)
		return (0);
	memset(&mygame, 0, sizeof(t_so_long));
	read_map(&mygame, argv);
	mygame.mlx = mlx_init();
	mygame.window = mlx_new_window(mygame.mlx, (mygame.img_width * 100),
			(mygame.img_height * 100), "so_long");
	errors(&mygame);
	init_img(&mygame);
	map_base(&mygame);
	paint_map(&mygame);
	mlx_hook(mygame.window, 2, (1L << 0), player_move, &mygame);
	mlx_hook(mygame.window, 17, (1L << 17), exit_game, &mygame);
	mlx_loop(mygame.mlx);
	return (0);
}
