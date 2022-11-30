/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:44 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/30 13:59:43 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <int2.h>
#include <window.h>
#include <input.h>

#include <mlx.h>

//void	draw_line(t_framebuf buf, void *mlx_win, t_int2 a, t_int2 b)
//{
//	const t_int2	dif = int2_sub(b, a);
//	t_int2 			out;
//	
//	out.x = a.x;
//	while (out.x <= b.x)
//	{
//		out.y = a.y + dif.y * (out.x - a.x) / dif.x;
//		mlx_pixel_put(mlx_ptr, mlx_win, x_out, y_out, 0x00FFFFFF);
//		x_out++;
//	}
//}

typedef struct s_framebuf
{
	void	*mlx_image;
	char	*data;
	int		width;
	int		height;
} t_framebuf;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window win;

	if (!window_init(&win, 1280, 720, "FdF"))
		return (1);
	mlx_key_hook(win.winptr, key_hook, &win);
	mlx_loop(win.mlxptr);
}
