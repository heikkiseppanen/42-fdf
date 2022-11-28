/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:44 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/28 19:03:03 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	void	*mlx_context;
	void	*mlx_window;
	void	*mlx_image;

	mlx_context = mlx_init();
	mlx_window = mlx_new_window(mlx_context, 1280, 720, "FdF");
	mlx_image = mlx_new_image(mlx_context, 1280, 720);
	mlx_clear_window(mlx_context, mlx_window);
	mlx_put_image_to_window(mlx_context, mlx_window, mlx_image, 0, 0);
	mlx_loop(mlx_context);
	return (0);
}
