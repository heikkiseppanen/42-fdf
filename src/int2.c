/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/02 11:26:34 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int2.h"

#include <math.h>

t_int2 int2_add(t_int2 a, t_int2 b)
{
	t_int2 sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

t_int2 int2_sub(t_int2 a, t_int2 b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

t_int2 int2_rotate(t_int2 a, double rad)
{
	a.x = a.x * cos(rad) - a.y * sin(rad);
	a.y = a.x * sin(rad) + a.y * cos(rad);
	return (a);
}
