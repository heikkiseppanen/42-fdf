/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float4x4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:53:18 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/07 16:20:19 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

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
	const t_float4x4	out = {
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

	return (out);
}

t_float4x4  float4x4_ortho(const t_float3 *a, const t_float3 *b)
{
	const t_float4x4 proj = {
	{2 / (b->x - a->x), 0.0, 0.0, -((b->x + a->x) / (b->x - a->x))},
	{0.0, 2 / (b->y - a->y), 0.0, -((b->y + a->y) / (b->y - a->y))},
	{0.0, 0.0, -2 / (b->z - a->z), -((b->z + a->z) / (b->z - a->z))},
	{0.0, 0.0, 0.0, 1.0}
	};
	return (proj);
}
