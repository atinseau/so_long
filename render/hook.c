/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthurtinseau <arthurtinseau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:46:56 by arthur            #+#    #+#             */
/*   Updated: 2021/06/24 16:19:05 by arthurtinse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	key_press(t_game *game, int key)
{
	close_window(key, game);
	player_move(key, game);
	return (1);
}

int	stop_hook(t_game *game, int key)
{
	if (key == UP)
	{
		game->map.player.falling = 1;
		game->map.player.jumping = 0;
	}
	if (key == LEFT || key == RIGHT)
	{
		game->map.player.moving = 0;
		game->map.player.inertie = (WIDTH / CHUNCK_SIZE) / 2;
		game->map.player.delay = 1;
	}
	return (0);
}

int	register_key(int key, t_game *game)
{
	if (!search_input(game->input, key))
		add_input(&game->input, key);
	return (1);
}

int	unregister_key(int key, t_game *game)
{
	if (search_input(game->input, key))
	{
		stop_hook(game, key);
		remove_input(&game->input, key);
	}
	return (1);
}

void	register_hook(t_game *game)
{
	if (OS == 0)
		mlx_hook(game->window, 17, 1L << 5, exit_game, game);
	else if (OS == 1)
		mlx_hook(game->window, 33, 1L << 17, exit_game, game);
	mlx_hook(game->window, 02, (1L << 0), register_key, game);
	mlx_hook(game->window, 03, (1L << 1), unregister_key, game);
	mlx_loop_hook(game->mlx, rendering, game);
}
