/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/15 14:52:30 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "ft_math.h"
#include "window.h"

#include "libft.h"

typedef struct s_mesh
{
	t_dynarr	vertex_arr;
	int			width;
	int			depth;
}	t_mesh;

typedef struct s_draw_param
{
	t_float3		pos;
	t_float3		scale;
	t_float3		rot;
	t_float4x4		view;
	t_float4x4		project;
	unsigned int	color;
}	t_draw_param;

int		mesh_from_map(t_mesh *empty, const char *filepath);
void	mesh_destroy(t_mesh *);

int		draw_wireframe(t_framebuf *out, t_mesh *mesh, t_draw_param *params);
void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color);

#endif
