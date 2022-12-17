/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:26:30 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/16 15:54:15 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <math.h>

t_float3	float3_transform(const t_float4x4 *l, const t_float3 *r)
{
	t_float3	out;
	float		out_w;

	out.x = l->a.x * r->x + l->a.y * r->y + l->a.z * r->z + l->a.w;
	out.y = l->b.x * r->x + l->b.y * r->y + l->b.z * r->z + l->b.w;
	out.z = l->c.x * r->x + l->c.y * r->y + l->c.z * r->z + l->c.w;
	out_w = l->d.x * r->x + l->d.y * r->y + l->d.z * r->z + l->d.w;
	if (out_w != 1.0)
	{
		out.x /= out_w;
		out.y /= out_w;
		out.z /= out_w;
	}
	return (out);
}

t_float3 float3_rot_x(const t_float3 *l, float rad)
{
	t_float3	out;
	const float	dcos = cosf(rad);
	const float	dsin = sinf(rad);

	out.x = l->x;
	out.y = l->y * dcos + l->y * -dsin;
	out.z = l->z * dsin + l->z * dcos; 
	return (out);
}

t_float3 float3_rot_y(const t_float3 *l, float rad)
{
	t_float3	out;
	const float	dcos = cosf(rad);
	const float	dsin = sinf(rad);

	out.x = l->x * dcos + l->x * dsin;
	out.y = l->y;
	out.z = l->z * -dsin + l->z * dcos; 
	return (out);
}

t_float3 float3_rot_z(const t_float3 *l, float rad)
{
	t_float3	out;
	const float	dcos = cosf(rad);
	const float	dsin = sinf(rad);

	out.x = l->x * dcos + l->x * -dsin;
	out.y = l->y * dsin + l->y * dcos;
	out.z = l->z; 
	return (out);
}
