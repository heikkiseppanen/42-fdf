/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/17 11:19:45 by hseppane         ###   ########.fr       */
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

t_float3	float3_cross(const t_float3 *l, const t_float3 *r)
{
	t_float3 out;

	out.x = l->y * r->z - l->z * r->y;
	out.y = l->z * r->x - l->x * r->z;
	out.z = l->x * r->y - l->y * r->x;
	return (out);
}

float	float3_len(const t_float3 *vec)
{
	return (sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
}

t_float3	float3_normalize(const t_float3 *vec)
{
	float		len;
	t_float3	out;

	len = float3_len(vec);
	out.x = vec->x / len; 
	out.y = vec->y / len; 
	out.z = vec->z / len; 
	return (out);
}
