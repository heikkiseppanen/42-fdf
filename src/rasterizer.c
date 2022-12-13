/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/13 15:01:23 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include "window.h"
#include "ft_math.h"

#include <mlx.h>
#include <math.h> // For M_PI

// TODO big-endian support

void	put_pixel(t_framebuf *buf, t_int2 pos, unsigned int color)
{
	int	offset;

	if (pos.x < 0 || pos.y < 0 || pos.x >= buf->width || pos.y >= buf->height)
		return ;
	offset = pos.x * buf->color_bytes + pos.y * buf->width * buf->color_bytes;
	if (buf->color_bytes == 4)
		*(unsigned int*)(buf->data + offset) = color;
	if (buf->color_bytes == 2)
		*(unsigned short*)(buf->data + offset) = color & 0xFFFF;
}

void	draw_line(t_framebuf *buf, t_float3 a, t_float3 b, unsigned int color)
{
	t_float3 tmp;
	t_int2	out;
	t_int2	p1;
	t_int2	p2;
	t_int2	dif;

	if (a.x > b.x)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	p1.x = buf->width  / 2 + (a.x * (buf->width / 2)); 
	p1.y = buf->height / 2 + (a.z * (buf->height / 2)); 
	p2.x = buf->width  / 2 + (b.x * (buf->width / 2)); 
	p2.y = buf->height / 2 + (b.z * (buf->height / 2)); 
	dif = int2_sub(p1, p2);
	out.x = p1.x;
	while (out.x <= p2.x)
	{
		out.y = p1.y + dif.y * (out.x - p1.x) / dif.x;
		put_pixel(buf, out, color);
		out.x++;
	}
}

int	draw_wireframe(t_framebuf *out, t_mesh *mesh, t_draw_params *params)
{
	const t_float3	*vertices = mesh->vertex_arr.ptr;
	int	x;
	int	y; 
	t_float4x4		matrix;
	t_float3	a;
	t_float3	b;
	
	matrix = float4x4_id();
	matrix = float4x4_scale(&matrix, &params->scale);
	matrix = float4x4_rotate(&matrix, &params->rotation);
	matrix = float4x4_translate(&matrix, &params->position);
	matrix = float4x4_mul(&matrix, &params->projection);
	matrix = float4x4_mul(&matrix, &params->view);
	x = 0;
	y = 0;
	while (y < mesh->depth)
	{
		while (x < mesh->width - 1)
		{
			a = float3_transform(&vertices[x + y * mesh->width], &matrix);
			b = float3_transform(&vertices[x + y * mesh->width + 1], &matrix);
			draw_line(out, a, b, 0x00FFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
