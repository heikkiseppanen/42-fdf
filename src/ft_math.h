/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:59:59 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/07 19:36:11 by hseppane         ###   ########.fr       */
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
	t_float4 a;
	t_float4 b;
	t_float4 c;
	t_float4 d;
}	t_float4x4;

t_float3 	float3_add(const t_float3 *l, const t_float3 *r);
t_float3	float3_sub(const t_float3 *l, const t_float3 *r);
t_float3	float3_rot(const t_float3 *l, const t_float3 *axis, double angle);
t_float3	float3_transform(const t_float4x4 *l, const t_float3 *r);

t_float4x4	float4x4_id(void);
t_float4x4	float4x4_mul(const t_float4x4 *l, const t_float4x4 *r);
t_float4x4	float4x4_ortho(const t_float4x4 *l, const t_float3 *a, const t_float3 *b);
t_float4x4	float4x4_rot(const t_float4x4 *l, const t_float3 *a, double angle);

#endif
