/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/04 19:48:50 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int2.h"

#include <math.h>

t_float3 float3_add(t_float3 a, t_float3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_float3 float3_sub(t_float3 a, t_float3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_float3 float3_rotate(t_float3 a, double rad)
{
	t_float3 new;

	new.x = (a.x * cos(rad)) - (a.y * sin(rad));
	new.y = (a.x * sin(rad)) + (a.y * cos(rad));
	new.z = 0; // TODO
	return (new);
}
