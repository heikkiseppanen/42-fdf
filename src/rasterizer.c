/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/16 11:46:48 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

#include "window.h"
#include "ft_math.h"

#include <mlx.h> // For M_PI

static t_dynarr	to_scr_space(t_dynarr *vert, t_float4x4 *mat, t_framebuf *buf)
{
	const t_int2	mid = {buf->width / 2, buf->height / 2};
	size_t			i;
	t_float3		clip;
	t_dynarr		screen_coords;
	t_int2			screen;

	screen_coords.ptr = NULL;
	if (!dynarr_init(&screen_coords, vert->size, sizeof(t_int2)))
		return (screen_coords);
	i = 0;
	while (i < vert->size)
	{
		clip = float3_transform(mat, *((t_float3 *)vert->ptr + i));
		screen.x = (mid.x + (mid.x * clip.x)) + 0.5; 
		screen.y = (mid.y - (mid.y * clip.y)) + 0.5; 
		if (!dynarr_pushback(&screen_coords, &screen, 1))
			break;
		i++;
	}
	return (screen_coords);
}

static void	draw_col(t_framebuf *buf, t_int2 *start, int points, int offset)
{
	while (--points)
	{
		draw_line(buf, *start, *(start + offset), 0x00FFFFFF);
		start += offset;
	}
}

static void	draw_row(t_framebuf *buf, t_int2 *start, int points)
{
	while (--points)
	{
		draw_line(buf, *start, *(start + 1), 0x00FFFFFF);
		start++;
	}
}

int	draw_mesh(t_framebuf *buf, t_mesh *mesh, t_float4x4 *matrix)
{
	t_dynarr	screen_coord; 
	t_int2		*coords;
	t_int2		i;

	framebuf_clear(buf);
	screen_coord = to_scr_space(&mesh->position_buffer, matrix, buf);
	coords = screen_coord.ptr;
	if (!coords)
		return (0);
	i = (t_int2){0, 0};
	while (i.x < mesh->width)
	{
		draw_col(buf, coords + i.x, mesh->depth, mesh->width);
		i.x++;
	}
	while (i.y < mesh->depth)
	{
		draw_row(buf, coords + (i.y * mesh->width), mesh->width);
		i.y++;
	}
	dynarr_del(&screen_coord);
	return (1);
}
