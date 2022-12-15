/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/15 15:22:01 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include "window.h"
#include "ft_math.h"

#include <mlx.h>
#include <math.h> // For M_PI

static t_float4x4	combine_matrices(t_draw_param *param)
{
	t_float4x4	model;
	t_float4x4	combi;
	
	model = float4x4_model(&param->pos, &param->rot, &param->scale);
	combi = float4x4_mul(&param->project, &param->view);
	combi = float4x4_mul(&combi, &model);

	return (combi);
}

static t_dynarr	to_scr_space(t_dynarr *v, const t_float4x4 *m, t_framebuf *b)
{
	const t_int2	mid = {b->width / 2, b->height / 2};
	size_t			i;
	t_float3		clip;
	t_dynarr		screen_coords;
	t_int2			screen;

	screen_coords.ptr = NULL;
	if (!dynarr_init(&screen_coords, v->size, sizeof(t_int2)))
		return (screen_coords);
	i = 0;
	while (i < v->size)
	{
		clip = float3_transform(m, (t_float3 *)v->ptr + i);
		screen.x = (mid.x + (mid.x * (clip.x))) + 0.5; 
		screen.y = (mid.y - (mid.y * (clip.y))) + 0.5; 
		if (!dynarr_pushback(&screen_coords, &screen, 1))
			break;
		i++;
	}
	return (screen_coords);
}

int	draw_wireframe(t_framebuf *buf, t_mesh *mesh, t_draw_param *param)
{
	const t_float4x4	mat = combine_matrices(param);
	const t_dynarr		scr_coords = to_scr_space(&mesh->vertex_arr, &mat, buf);
	const t_int2		*coord = scr_coords.ptr;
	t_int2				i;
	unsigned int		ci;

	if (!scr_coords.ptr)
		return (0);
	i.y = 0;
	while (i.y < mesh->depth - 1)
	{
		i.x = 0;
		while (i.x < mesh->width - 1)
		{
			ci = (i.x++) + i.y * mesh->width;
			draw_line(buf, coord[ci], coord[ci + 1], 0x00FFFFFF);
			draw_line(buf, coord[ci], coord[ci + mesh->width], 0x00FFFFFF);
		}
		i.y++;
	}
	dynarr_del((t_dynarr *)&scr_coords);
	return (1);
}
