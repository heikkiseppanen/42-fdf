/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:09:47 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/13 14:11:17 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_int2	int2_add(t_int2 l, t_int2 r)
{
	t_int2 out;

	out.x = l.x + r.x;
	out.y = l.y + r.y;
	return (out);
}

t_int2	int2_sub(t_int2 l, t_int2 r)
{
	t_int2 out;

	out.x = l.x - r.x;
	out.y = l.y - r.y;
	return (out);
}
