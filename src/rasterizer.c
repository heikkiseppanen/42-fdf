/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/21 10:41:08 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

#include "window.h"
#include "ft_math.h"

#include <mlx.h> // For M_PI

static t_dynarr	to_scr_space(t_dynarr *vert, t_float4x4 *mat, t_framebuf *buf)
{
	const t_vertex	*it = vert->ptr;
	const t_vertex	*end = it + vert->size;
	const t_int2	mid = {buf->width / 2, buf->height / 2};
	t_dynarr		screen_coords;
	t_vertex		vertex;

	screen_coords = (t_dynarr){};
	if (!dynarr_init(&screen_coords, vert->size, sizeof(t_vertex)))
		return (screen_coords);
	while (it != end)
	{
		vertex.position = float3_transform(mat, it->position);
		vertex.position.x = (mid.x + (mid.x * vertex.position.x)) + 0.5;
		vertex.position.y = (mid.y - (mid.y * vertex.position.y)) + 0.5;
		vertex.color = it->color;
		if (!dynarr_pushback(&screen_coords, &vertex, 1))
			break ;
		it++;
	}
	return (screen_coords);
}

static void	draw_col(t_framebuf *buf, t_vertex *start, int points, int offset)
{
	t_int2	a;
	t_int2	b;
	t_float3 c0;
	t_float3 c1;

	while (--points)
	{
		a = (t_int2){start->position.x, start->position.y};
		c0 = start->color;
		start += offset;
		b = (t_int2){start->position.x, start->position.y};
		c1 = start->color;
		draw_line(buf, a, b, c0, c1);
	}
}

static void	draw_row(t_framebuf *buf, t_vertex *start, int points)
{
	t_int2	a;
	t_int2	b;
	t_float3 c0;
	t_float3 c1;

	while (--points)
	{
		a = (t_int2){start->position.x, start->position.y};
		c0 = start->color;
		start++;
		b = (t_int2){start->position.x, start->position.y};
		c1 = start->color;
		draw_line(buf, a, b, c0, c1);
	}
}

int	draw_mesh(t_framebuf *buf, t_mesh *mesh, t_float4x4 *matrix)
{
	t_dynarr	transformed_vertices;
	t_vertex	*vertex;
	t_int2		i;

	framebuf_clear(buf, 0x002E3440);
	transformed_vertices = to_scr_space(&mesh->vertex_buffer, matrix, buf);
	vertex = transformed_vertices.ptr;
	if (!vertex)
		return (0);
	i = (t_int2){0, 0};
	while (i.x < mesh->width)
	{
		draw_col(buf, vertex + i.x, mesh->depth, mesh->width);
		i.x++;
	}
	while (i.y < mesh->depth)
	{
		draw_row(buf, vertex + (i.y * mesh->width), mesh->width);
		i.y++;
	}
	dynarr_del(&transformed_vertices);
	return (1);
}
