/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:04:03 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/29 11:59:39 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <int2.h>

t_int2 int2_add(t_int2 a, t_int2 b)
{
	t_int2 sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

t_int2 int2_sub(t_int2 a, t_int2 b)
{
	t_int2 dif;

	dif.x = a.x - b.x;
	dif.y = a.y - b.y;
	return (dif);
}
