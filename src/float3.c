/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/14 18:56:04 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <math.h>

t_float3	float3_add(const t_float3 *l, const t_float3 *r)
{
	t_float3 out;

	out.x = l->x + r->x;
	out.y = l->y + r->y;
	out.z = l->z + r->z;
	return (out);
}

t_float3	float3_sub(const t_float3 *l, const t_float3 *r)
{
	t_float3 out;

	out.x = l->x - r->x;
	out.y = l->y - r->y;
	out.z = l->z - r->z;
	return (out);
}

t_float3	float3_neg(const t_float3 *vec)
{
	t_float3 out;

	out.x = -vec->x;
	out.y = -vec->y;
	out.z = -vec->z;
	return (out);
}

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
