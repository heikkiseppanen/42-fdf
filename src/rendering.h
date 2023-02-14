/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:12:49 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/14 15:55:31 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "window.h"
# include "mesh.h"
# include "scene.h"
# include "ft_math.h"

typedef struct s_shader_param
{
	t_float4	projection_matrix;
	t_float4	view_matrix;
	t_float4	model_matrix;
}	t_shader_param;

typedef struct s_renderer
{
}	t_renderer;

int	render_scene(const t_scene *scene, t_framebuf *target_buffer);

int	draw_grid(const t_int3 *coords, int width, int height, t_framebuf *buf);

#endif
