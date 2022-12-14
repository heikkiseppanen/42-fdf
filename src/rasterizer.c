/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 16:10:39 by hseppane         ###   ########.fr       */
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
	p1.y = buf->height / 2 - (a.y * (buf->height / 2)); 
	p2.x = buf->width  / 2 + (b.x * (buf->width / 2)); 
	p2.y = buf->height / 2 - (b.y * (buf->height / 2)); 
	dif = int2_sub(p1, p2);
	if (!dif.x)
		return ;
	out.x = p1.x;
	while (out.x <= p2.x)
	{
		out.y = p1.y + dif.y * (out.x - p1.x) / dif.x;
		put_pixel(buf, out, color);
		out.x++;
	}
}

static t_float4x4	combination_matrix(t_draw_param *param)
{
	t_float4x4	model;
	t_float4x4	combi;
	
	model = float4x4_model(&param->pos, &param->rot, &param->scale);
	combi = float4x4_id();
	combi = float4x4_mul(&param->project, &param->view);
	combi = float4x4_mul(&combi, &model);

	return (combi);
}

int	draw_wireframe(t_framebuf *out, t_mesh *mesh, t_draw_param *param)
{
	const t_float3		*vert = mesh->vertex_arr.ptr;
	const t_float4x4	mat = combination_matrix(param);
	t_int2				i;
	unsigned int		offset;
	t_float3			p[4];

	i = (t_int2){0, 0};
	while (i.y < mesh->depth - 1)
	{
		while (i.x < mesh->width - 1)
		{
			offset = i.x + i.y * mesh->width;
			p[0] = float3_transform(&mat, &vert[offset]);
			p[1] = float3_transform(&mat, &vert[offset + 1]);
			p[2] = float3_transform(&mat, &vert[offset + mesh->width + 1]);
			p[3] = float3_transform(&mat, &vert[offset + mesh->width]);
			draw_line(out, p[0], p[1], 0x00FFFFFF);
			draw_line(out, p[1], p[2], 0x00FFFFFF);
			draw_line(out, p[2], p[3], 0x00FFFFFF);
			draw_line(out, p[3], p[0], 0x00FFFFFF);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (1);
}
