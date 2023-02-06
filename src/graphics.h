/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/06 15:10:50 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "window.h"
#include "scene.h"
#include "ft_math.h"

#include "libft.h"

typedef struct s_mesh
{
	t_dynarr	vertex_arr;
	//t_dynarr	color_arr;
	float		width;
	float		height;
	float		depth;
}	t_mesh;

typedef struct s_draw_param
{
	t_float4x4	model;
	t_float4x4	view;
	t_float4x4	project;
}	t_draw_param;

int		mesh_from_map(t_mesh *empty, const char *filepath);
void	mesh_del(t_mesh *mesh);

int		render_scene(const t_scene *scene, t_framebuf *target_buffer);

int		draw_grid(t_framebuf *buf, t_mesh *grid_mesh);
void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color);

#endif
