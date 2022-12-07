/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/07 16:23:31 by hseppane         ###   ########.fr       */
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

//t_float3	ft_float3_dot(t_float3 *a, t_float3 *b)
//{
//}
//
t_float3	float3_transform(const t_float4x4 *l, const t_float3 *r)
{
	const t_float4 out = {
	l->a.x * r->x + l->a.y * r->y + l->a.z * r->z + l->a.w,
		l->b.x * r->x + l->b.y * r->y + l->b.z * r->z + l->b.w,
		l->c.x * r->x + l->c.y * r->y + l->c.z * r->z + l->c.w,
		l->d.x * r->x + l->d.y * r->y + l->d.z * r->z + l->d.w
	};
	
	return ((t_float3){out.x / out.w, out.y / out.w, out.z / out.w});
}

t_float3	float3_rotate(const t_float3 *l, const t_float3 *axis, double rad)
{
	t_float3 out;

	(void)axis;
	out.x = (l->x * cos(rad)) - (l->y * sin(rad));
	out.y = (l->x * sin(rad)) + (l->y * cos(rad));
	out.z = 0; // TODO
	return (out);
}
