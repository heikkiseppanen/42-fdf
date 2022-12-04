/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:59:59 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/04 19:49:10 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT3_H
# define FLOAT3_H

typedef struct s_float3
{
	float	x;
	float	y;
	float	z;
}	t_float3;

t_float3 	float3_add(t_float3 a, t_float3 b);
t_float3	float3_sub(t_float3 a, t_float3 b);
t_float3	float3_rotate(t_float3 a, double rad);

#endif
