/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:27:01 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/17 14:39:53 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

#include "ft_math.h"

typedef struct s_input
{
	char	movekey;
	char	rotkey;
	float	scroll_sens;
	float	mouse_sens;
	t_int2	mouse_position;
	t_int2	mouse_movement;
}	t_input;

int key_hook(int keycode, void *param);

int	mousedown_hook(int button, int x, int y, void *param);
int	mouseup_hook(int button, int x, int y, void *param);
int	mousemove_hook(int x, int y, void *param);

#endif
