/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:40:23 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/29 17:34:36 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_map_unit(char **argv)
{
	int		fdnbr;
	int		linenbr;
	char	*str;

	fdnbr = open(argv[1], O_RDONLY);
	linenbr = 0;
	while (1)
	{
		str = get_next_line(fdnbr);
		if (!str)
			break ;
		free (str);
		linenbr++;
	}
	close(fdnbr);
	return (linenbr);
}

void	read_map(t_so_long *mygame, char **argv)
{
	int		fdnbr;
	int		linenbr;
	char	*str;

	linenbr = count_map_unit(argv);
	fdnbr = open(argv[1], O_RDONLY);
	mygame->map.map = (char **)malloc(linenbr * sizeof(char *));
	linenbr = 0;
	while (1)
	{
		str = get_next_line(fdnbr);
		if (!str)
			break ;
		mygame->map.map[linenbr] = str;
		linenbr++;
	}
	close(fdnbr);
	mygame->img_height = linenbr;
	mygame->img_width = ft_strlen(mygame->map.map[0]);
}

void	map_base(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = 0;
	jwidth = 0;
	while (iheight < mygame->img_height)
	{
		while (jwidth < mygame->img_width)
		{
			paint_path(jwidth, iheight, mygame);
			jwidth++;
		}
		iheight++;
		jwidth = 0;
	}
}

void	paint_map(t_so_long *mygame)
{
	int	iheight;
	int	jwidth;

	iheight = 0;
	jwidth = 0;
	while (iheight < mygame->img_height)
	{
		while (jwidth < mygame->img_width)
		{
			if (mygame->map.map[iheight][jwidth] == '1')
				paint_wall(jwidth, iheight, mygame);
			else if (mygame->map.map[iheight][jwidth] == 'P')
				set_player(jwidth, iheight, mygame);
			else if (mygame->map.map[iheight][jwidth] == 'C')
				set_collect(jwidth, iheight, mygame);
			else if (mygame->map.map[iheight][jwidth] == 'E')
				paint_exit(jwidth, iheight, mygame);
			jwidth++;
		}
		iheight++;
		jwidth = 0;
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
