/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 14:22:11 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "ft_math.h"
#include "window.h"

typedef struct s_mesh
{
	t_dynarr		*vertex_arr;
	t_dynarr		*index_arr;
}	t_mesh;

typedef struct s_draw_params
{
	t_float3		pos;
	t_float3		rot;
	unsigned int	color;
}	t_draw_params;

int		mesh_load(t_mesh *empty, char *filepath);
void	mesh_destroy(t_mesh *);

int		draw_wireframe(t_framebuf *out, t_mesh *mesh, unsigned int color);

#endif
