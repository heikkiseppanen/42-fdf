/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:49 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/20 10:26:09 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "window.h"
# include "mesh.h"
# include "ft_math.h"

int		draw_mesh(t_framebuf *buf, t_mesh *mesh, t_float4x4 *matrix);
void	draw_line(t_framebuf *to, t_int2 a, t_int2 b, t_float3 c0, t_float3 c1);

#endif
