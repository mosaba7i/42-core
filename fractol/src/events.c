/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:28:51 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/11 13:46:46 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define KEY_ESC 65307
#define KEY_PLUS 61
#define KEY_MINUS 45
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364

static void	move_keys(int keycode, t_fractol *f)
{
	if (keycode == KEY_LEFT)
		f->offset_x -= 0.05 / f->zoom;
	else if (keycode == KEY_RIGHT)
		f->offset_x += 0.05 / f->zoom;
	else if (keycode == KEY_UP)
		f->offset_y -= 0.05 / f->zoom;
	else if (keycode == KEY_DOWN)
		f->offset_y += 0.05 / f->zoom;
	else if (keycode == KEY_PLUS)
		f->zoom *= 1.1;
	else if (keycode == KEY_MINUS)
		f->zoom /= 1.1;
}

int	key_hook(int keycode, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keycode == KEY_ESC)
		close_hook(f);
	move_keys(keycode, f);
	render(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom /= 1.1;
	render(f);
	return (0);
}

int	close_hook(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
	return (0);
}
