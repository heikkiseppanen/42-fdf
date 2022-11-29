/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:59:59 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/29 11:58:36 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT3_H
# define FLOAT3_H

typedef struct int2
{
	int	x;
	int	y;
}	t_int2;

t_int2 	int2_add(t_int2 a, t_int2 b);
t_int2	int2_sub(t_int2 a, t_int2 b);

#endif
