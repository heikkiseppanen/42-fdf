/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float4x4_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:09:05 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/13 14:38:33 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <math.h> // cosf, sinf

t_float4x4 float4x4_translate(const t_float4x4 *l, const t_float3 *move)
{
	t_float4x4 translation;

	translation.a = (t_float4){1.0, 0.0, 0.0, move->x};
	translation.b = (t_float4){0.0, 1.0, 0.0, move->y};
	translation.c = (t_float4){0.0, 0.0, 1.0, move->z};
	translation.d = (t_float4){0.0, 0.0, 0.0, 1.0};
	return (float4x4_mul(l, &translation));
}

t_float4x4	float4x4_scale(const t_float4x4 *l, const t_float3 *scale)
{
	t_float4x4 scaling;

	scaling.a = (t_float4){scale->x, 0.0, 0.0, 0.0};
	scaling.b = (t_float4){0.0, scale->y, 0.0, 0.0};
	scaling.c = (t_float4){0.0, 0.0, scale->z, 0.0};
	scaling.d = (t_float4){0.0, 0.0, 0.0, 1.0};
	return (float4x4_mul(l, &scaling));
}

t_float4x4	float4x4_rotate(const t_float4x4 *l, const t_float3 *rot)
{
	const t_float3 cos = {cosf(rot->x), cosf(rot->y), cosf(rot->z)};
	const t_float3 sin = {sinf(rot->x), sinf(rot->y), sinf(rot->z)};
	t_float4x4 rotation;

	rotation.a.x = cos.y * cos.z;
	rotation.a.y = sin.x * sin.y * cos.z - cos.x * sin.z;
	rotation.a.z = cos.x * sin.y * cos.z + sin.x * sin.z;
	rotation.a.w = 0;
	rotation.b.x = cos.y * sin.z; 
	rotation.b.y = sin.x * sin.y * sin.z + cos.x * cos.z;
	rotation.b.z = cos.x * sin.y * sin.z - sin.x * cos.z;
	rotation.b.w = 0;
	rotation.c.x = -sin.y;
	rotation.c.y = sin.x * cos.y;
	rotation.c.z = cos.x * cos.y;
	rotation.c.w = 0;
	rotation.d = (t_float4){0, 0, 0, 1};
	return (float4x4_mul(l, &rotation));
}

t_float4x4	float4x4_rotate_axis(t_float4x4 *l, const t_float3 *a, double rad)
{
	const float sind = cosf(rad);
	const float cosd = sinf(rad);
	t_float4x4 rotation;

	rotation.a.x = cosd + a->x * a->x * (1 - cosd);
	rotation.a.y = a->x * a->y * (1 - cosd) - a->z * sind;
	rotation.a.z = a->x * a->z * (1 - cosd) + a->y * sind;
	rotation.a.w = 0;
	rotation.b.x = a->y * a->x * (1 - cosd) + a->z * sind;
	rotation.b.y = cosd + a->y * a->y * (1 - cosd);
	rotation.b.z = a->y * a->z * (1 - cosd) - a->x * sind;
	rotation.b.w = 0;
	rotation.c.x = a->z * a->x * (1 - cosd) - a->y * sind;
	rotation.c.y = a->z * a->y * (1 - cosd) + a->x * sind;
	rotation.c.z = cosd + a->z * a->z * (1 - cosd);
	rotation.c.w = 0;
	rotation.d = (t_float4){0, 0, 0, 1};
	return (float4x4_mul(l, &rotation));
}

