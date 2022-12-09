/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:26:30 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 09:45:08 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <math.h>

t_float3 float3_rot_x(t_float3 *l, float rad)
{
	t_float3	out;
	const float	dcos = cosf(rad);
	const float	dsin = sinf(rad);

	out.x = l->x;
	out.y = l->y * dcos + l->y * -dsin;
	out.z = l->z * dsin + l->z * dcos; 
}

t_float3 float3_rot_y(t_float3 *l, float rad)
{
	t_float3	out;
	const float	dcos = cosf(rad);
	const float	dsin = sinf(rad);

	out.x = l->x * dcos + l->x * dsin;
	out.y = l->y;
	out.z = l->z * -dsin + l->z * dcos; 
}

t_float3 float3_rot_z(t_float3 *l, float rad)
{
	t_float3	out;
	const float	dcos = cosf(rad);
	const float	dsin = sinf(rad);

	out.x = l->x * dcos + l->x * -dsin;
	out.y = l->y * dsin + l->y * dcos;
	out.z = l->z; 
}
