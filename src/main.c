/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:44 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 18:43:24 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <app.h>

#include <mlx.h>

#include <libft.h>

int main(int argc, char **argv)
{
	t_app fdf;

	if (argc != 2)
	{
		ft_printf("Use: fdf <map_path>");
		return (1);
	}
	if (!app_init(&fdf, argv[1]))
	{
		app_terminate(&fdf);
		return (1);
	}
	mlx_loop(fdf.win.mlx);
	return (1);
}
