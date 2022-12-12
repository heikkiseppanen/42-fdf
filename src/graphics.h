/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/12 14:26:13 by hseppane         ###   ########.fr       */
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

typedef struct s_gfx
{
	t_float3	transform;
	t_float3	viewbox;
	t_float3	projection;
}	t_gfx;

int		mesh_from_map(t_mesh *empty, const char *filepath);
void	mesh_destroy(t_mesh *);

int		draw_wireframe(t_framebuf *out, t_mesh *mesh, t_gfx *params);

#endif
