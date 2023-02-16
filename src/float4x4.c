/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float4x4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:53:18 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/15 12:07:29 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <math.h>

t_float4x4	float4x4_id(void)
{
	const t_float4x4	a = {
	{1.0, 0.0, 0.0, 0.0},
	{0.0, 1.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}};

	return (a);
}

t_float4x4	float4x4_mul(const t_float4x4 *l, const t_float4x4 *r)
{
	const t_float4x4	result = {
	{l->a.x * r->a.x + l->a.y * r->b.x + l->a.z * r->c.x + l->a.w * r->d.x,
		l->a.x * r->a.y + l->a.y * r->b.y + l->a.z * r->c.y + l->a.w * r->d.y,
		l->a.x * r->a.z + l->a.y * r->b.z + l->a.z * r->c.z + l->a.w * r->d.z,
		l->a.x * r->a.w + l->a.y * r->b.w + l->a.z * r->c.w + l->a.w * r->d.w},
	{l->b.x * r->a.x + l->b.y * r->b.x + l->b.z * r->c.x + l->b.w * r->d.x,
		l->b.x * r->a.y + l->b.y * r->b.y + l->b.z * r->c.y + l->b.w * r->d.y,
		l->b.x * r->a.z + l->b.y * r->b.z + l->b.z * r->c.z + l->b.w * r->d.z,
		l->b.x * r->a.w + l->b.y * r->b.w + l->b.z * r->c.w + l->b.w * r->d.w},
	{l->c.x * r->a.x + l->c.y * r->b.x + l->c.z * r->c.x + l->c.w * r->d.x,
		l->c.x * r->a.y + l->c.y * r->b.y + l->c.z * r->c.y + l->c.w * r->d.y,
		l->c.x * r->a.z + l->c.y * r->b.z + l->c.z * r->c.z + l->c.w * r->d.z,
		l->c.x * r->a.w + l->c.y * r->b.w + l->c.z * r->c.w + l->c.w * r->d.w},
	{l->d.x * r->a.x + l->d.y * r->b.x + l->d.z * r->c.x + l->d.w * r->d.x,
		l->d.x * r->a.y + l->d.y * r->b.y + l->d.z * r->c.y + l->d.w * r->d.y,
		l->d.x * r->a.z + l->d.y * r->b.z + l->d.z * r->c.z + l->d.w * r->d.z,
		l->d.x * r->a.w + l->d.y * r->b.w + l->d.z * r->c.w + l->d.w * r->d.w}};
	return (result);
}

t_float4x4	float4x4_model(const t_transform *transform)
{
	const t_float4x4	move = float4x4_translation(&transform->position);
	const t_float4x4	rotate = float4x4_rotation(&transform->rotation);
	const t_float4x4	scale = float4x4_scaling(&transform->scale);
	t_float4x4			model_matrix;

	model_matrix = float4x4_mul(&move, &rotate);
	model_matrix = float4x4_mul(&model_matrix, &scale);
	return (model_matrix);
}

t_float4x4	float4x4_ortho(float size, float aspect, float zmin, float zmax)
{
	const t_float3	min = {-size * aspect, -size, zmin}; 
	const t_float3	max = {size * aspect, size, zmax}; 
	t_float4x4	proj;
	
	proj.a.x = 2 / (max.x - min.x);
	proj.a.y = 0.0;
	proj.a.z = 0.0;
	proj.a.w = -((max.x + min.x) / (max.x - min.x));
	proj.b.x = 0.0;
	proj.b.y = 2 / (max.y - min.y);
	proj.b.z = 0.0;
	proj.b.w = -((max.y + min.y) / (max.y - min.y));
	proj.c.x = 0.0;
	proj.c.y = 0.0;
	proj.c.z = -2 / (max.z - min.z);
	proj.c.w = -((max.z + min.z) / (max.z - min.z));
	proj.d = (t_float4){0.0, 0.0, 0.0, 1.0};
	return (proj);
}

t_float4x4	float4x4_persp(float fov, float aspect, float zmin, float zmax)
{
	const float		size = tanf(fov/2) * zmin;
	const t_float3	min = {-size * aspect, -size, zmin}; 
	const t_float3	max = {size * aspect, size, zmax}; 
	t_float4x4	proj;
	
	proj.a.x = (2 * min.z) / (max.x - min.x);
	proj.a.y = 0.0;
	proj.a.z = (max.x + min.x) / (max.x - min.x);
	proj.a.w = 0.0;
	proj.b.x = 0.0;
	proj.b.y = (2 * min.z) / (max.y - min.y);
	proj.b.z = (max.y + min.y) / (max.y - min.y);
	proj.b.w = 0.0;
	proj.c.x = 0.0;
	proj.c.y = 0.0;
	proj.c.z = -(max.z + min.z) / (max.z - min.z);
	proj.c.w = (-2 * max.z * min.z) / (max.z - min.z);
	proj.d = (t_float4){0.0, 0.0, -1.0, 0.0};
	return (proj);
}

t_float4x4	float4x4_view(t_float3 pos, t_float3 target)
{
	t_float4x4	axis;
	t_float4x4	offset;
	t_float3	x;
	t_float3	y;
	t_float3	z;

	z = float3_sub(pos, target);
	z = float3_normalize(z);
	y = (t_float3){0.0, 1.0, 0.0};
	x = float3_cross(y, z);
	x = float3_normalize(x);
	y = float3_cross(z, x);
	axis.a = (t_float4){x.x, x.y, x.z, 0.0};
	axis.b = (t_float4){y.x, y.y, y.z, 0.0};
	axis.c = (t_float4){z.x, z.y, z.z, 0.0};
	axis.d = (t_float4){0.0, 0.0, 0.0, 1.0};
	offset.a = (t_float4){1.0, 0.0, 0.0, -pos.x};
	offset.b = (t_float4){0.0, 1.0, 0.0, -pos.y};
	offset.c = (t_float4){0.0, 0.0, 1.0, -pos.z};
	offset.d = (t_float4){0.0, 0.0, 0.0, 1.0};
	return (float4x4_mul(&axis, &offset));
}
