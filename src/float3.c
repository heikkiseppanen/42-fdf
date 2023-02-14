/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/14 12:40:36 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <math.h>

t_float3	float3_add(t_float3 l, t_float3 r)
{
	return ((t_float3){l.x + r.x, l.y + r.y, l.z + r.z});
}

t_float3	float3_sub(t_float3 l, t_float3 r)
{
	return ((t_float3){l.x - r.x, l.y - r.y, l.z - r.z});
}

t_float3	float3_scalar(t_float3 l, float multiplier)
{
	return ((t_float3){l.x * multiplier, l.y * multiplier, l.z * multiplier});
}

t_float3	float3_cross(t_float3 l, t_float3 r)
{
	return ((t_float3)
	{
		l.y * r.z - l.z * r.y,
		l.z * r.x - l.x * r.z,
		l.x * r.y - l.y * r.x
	});
}

float	float3_len(t_float3 vec)
{
	return (sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_float3	float3_normalize(t_float3 vector)
{
	const float	len = float3_len(vector);

	vector.x /= len;
	vector.y /= len; 
	vector.z /= len;
	return (vector);
}
