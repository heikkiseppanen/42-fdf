/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:59:59 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/06 17:02:11 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

typedef struct s_float3
{
	float	x;
	float	y;
	float	z;
}	t_float3;

typedef struct s_float4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_float4;

typedef struct s_float4x4
{
	float mat[4][4];
}	t_float4x4;

t_float3 	float3_add(t_float3 a, t_float3 b);
t_float3	float3_sub(t_float3 a, t_float3 b);
t_float3	float3_rotate(t_float3 a, t_float3 axis, double rad);

t_float4x4	float4x4_mul(t_float4x4 *a, t_float4x4 *b);
t_float4x4	float4x4_id(void);
t_float4x4  float4x4_ortho(t_float3 a, t_float3 b);
#endif
