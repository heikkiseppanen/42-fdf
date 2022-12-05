/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:50:44 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/05 15:29:54 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <app.h>
#include <mlx.h>

int main(int argc, char **argv)
{
	t_app fdf;

	(void)argc;
	(void)argv;
//	if (argc != 2)
//		return (1);
	if (!app_init(&fdf, "TMP")) // TODO USE ARG
		return (1);
	mlx_loop(fdf.win.mlx);
	return (1);
}
