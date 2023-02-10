/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:49 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/09 12:09:12 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "window.h"
# include "mesh.h"
# include "scene.h"
# include "ft_math.h"


int		render_scene(const t_scene *scene, t_framebuf *target_buffer);

int		draw_grid(t_framebuf *buf, t_mesh *grid_mesh);
void	draw_line(t_framebuf *buf, t_int2 a, t_int2 b, unsigned int color);

#endif
