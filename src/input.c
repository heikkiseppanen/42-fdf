/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:27:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/30 15:43:27 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#ifdef __linux__
# include "linux/keycodes.h"
#else
# include "macos/keycodes.h"
#endif

#include <stdio.h>
#include <stdlib.h>

int key_hook(int keycode, void *param)
{
	t_window *const	win = param;

	if (keycode == KEY_ESCAPE)
	{
		window_destroy(win);
		exit(0);
	}
	printf("%i\n", keycode);
	return (1);
}
