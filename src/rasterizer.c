/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 10:06:53 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include "window.h"
#include "ft_math.h"

#include <mlx.h>
#include <math.h> // For M_PI

// TODO big-endian support

void	put_pixel(t_framebuf *buf, t_float3 pos, unsigned int color)
{
	int	offset;

	if (pos.x < 0 || pos.z < 0 || pos.x >= buf->width || pos.z >= buf->height)
		return ;
	offset = (int)pos.x * buf->color_bytes + (int)pos.z * buf->width * buf->color_bytes;
	if (buf->color_bytes == 4)
		*(unsigned int*)(buf->data + offset) = color;
	if (buf->color_bytes == 2)
		*(unsigned short*)(buf->data + offset) = color & 0xFFFF;
}

void	draw_line(t_framebuf *buf, t_float3 a, t_float3 b, unsigned int color)
{
	t_float3	dif;
	t_float3	out;
	t_float3	tmp;

	if (a.x > b.x)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	a.x = buf->width  / 2 + (a.x * (buf->width / 2)); 
	a.z = buf->height / 2 + (a.z * (buf->height / 2)); 
	b.x = buf->width  / 2 + (b.x * (buf->width / 2)); 
	b.z = buf->height / 2 + (b.z * (buf->height / 2)); 
	dif = float3_sub(&b, &a);
	out.x = a.x;
	while (out.x <= b.x)
	{
		out.z = a.z + dif.z * (out.x - a.x) / dif.x;
		put_pixel(buf, out, color);
		out.x++;
	}
}

int	draw_wireframe(t_framebuf *out, t_mesh *mesh, unsigned int color)
{
	static float angle = 0.0;
	if (angle < 2 * M_PI)
		angle += 0.01;
	else
		angle = 0.0;
	unsigned int m = 0;
	unsigned int n = out->width * out->color_bytes * out->height;
	while (m < n)
		out->data[m++] = 0;
	unsigned int i;
	unsigned int a;
	unsigned int b;
	t_float4x4 trans = float4x4_id();
	const t_float3 oa = {-2.0, -2.0, 2.0};
	const t_float3 ob = {2.0, 2.0, -2.0};
	const t_float3 ax = {0.0, 1.0, 0.0};

	trans = float4x4_rot(&trans, &ax, angle);
	trans = float4x4_ortho(&trans, &oa, &ob);
	i = 0;
	while (i < 3)
	{
		a = mesh->idx[i++];
		b = mesh->idx[i];
		draw_line(out, 
				float3_transform(&trans, &mesh->vert[a]),
				float3_transform(&trans, &mesh->vert[b]), color);
	}
		a = mesh->idx[i];
		b = mesh->idx[i - 3];
		draw_line(out, 
				float3_transform(&trans, &mesh->vert[a]),
				float3_transform(&trans, &mesh->vert[b]), color);
	return (1);
}
