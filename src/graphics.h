/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/13 13:15:14 by hseppane         ###   ########.fr       */
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

typedef struct s_draw_params
{
	t_float3		position;
	t_float3		scale;
	t_float3		rotation;
	t_float4x4		view;
	t_float4x4		projection;
	unsigned int	color;
}	t_draw_params;

int		mesh_from_map(t_mesh *empty, const char *filepath);
void	mesh_destroy(t_mesh *);

int		draw_wireframe(t_framebuf *out, t_mesh *mesh, t_draw_params *params);

#endif
