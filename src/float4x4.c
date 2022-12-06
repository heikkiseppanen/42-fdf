/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float4x4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:53:18 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/06 16:59:24 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_float4x4	float4x4_id(void)
{
	const t_float4x4 a = {{
	{1.0, 0.0, 0.0, 0.0},
	{0.0, 1.0, 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}
	}};
	return (a);
}

t_float4x4	float4x4_mul(t_float4x4 *a, t_float4x4 *b)
{
	t_float4x4	out;
	int			i;
	int			j;
	int			k;
	
	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			out.mat[i][j] = 0;
			while (k < 4)
			{
				out.mat[i][j] += a->mat[i][k] * b->mat[k][j];
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (out);
}

t_float4x4  float4x4_ortho(t_float3 a, t_float3 b)
{
	const t_float4x4 proj = {{
	{2 / (b.x - a.x), 0.0, 0.0, -((b.x + a.x) / (b.x - a.x))},
	{0.0, 2 / (b.y - a.y), 0.0, -((b.y + a.y) / (b.y - a.y))},
	{0.0, 0.0, -2 / (b.z - a.z), -((b.z + a.z) / (b.z - a.z))},
	{0.0, 0.0, 0.0, 1.0}
	}};
	return (proj);
}
