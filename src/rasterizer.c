/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:17:21 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/12 15:05:13 by hseppane         ###   ########.fr       */
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

int	draw_wireframe(t_framebuf *out, t_mesh *mesh, t_gfx *params)
{
	const t_float3	*vertices;
	unsigned int	idx;
	float4x4		matrix;

	transform = float4x4_id();
	transform = float4x4_ortho	
	return (1);
}
