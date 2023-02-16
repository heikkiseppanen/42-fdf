/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:49 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/15 12:04:51 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "window.h"
# include "mesh.h"
# include "ft_math.h"

//typedef struct s_shader_param
//{
//	t_float4	projection_matrix;
//	t_float4	view_matrix;
//	t_float4	model_matrix;
//}	t_shader_param;

int		draw_mesh(t_framebuf *buf, t_mesh *mesh, t_float4x4 *matrix);
void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color);

#endif
