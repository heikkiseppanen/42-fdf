/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:14:20 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/14 14:00:14 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "input.h"
# include "mesh.h"
# include "ft_math.h"
# include "rendering.h"
	
typedef struct s_scene
{
	t_cam		camera;
	t_mesh		mesh;
	t_transform	camera_transform;
	t_transform	mesh_transform;
	t_shader_param shader_parameters;
}	t_scene;

int		scene_init(t_scene *empty, const char *mesh_path);
void	scene_del(t_scene *scene);

void	scene_update(t_scene *scene, const t_input *input);

#endif
