/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:27:01 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/09 10:45:00 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "ft_math.h"

# include <mlx.h>

typedef struct s_input
{
	char	exit;
	char	move;
	char	rotate;
	char	zoom_in;
	char	zoom_out;
	float	scroll_sens;
	float	mouse_sens;
	t_int2	mouse_position;
	t_int2	mouse_movement;
}	t_input;

void input_init(t_input *empty, void *mlx_window);

#endif
