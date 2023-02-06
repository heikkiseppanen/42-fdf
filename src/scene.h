/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:14:20 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/06 14:56:07 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "graphics.h"
# include "camera.h"
	
typedef struct s_scene
{
	t_cam		camera;
	t_mesh		mesh;
	t_transform	cam_transform;
	t_transform	mesh_transform;
}	t_scene;

int		scene_init(t_scene *empty, const char *mesh_path);
void	scene_del(t_scene *scene);

void	scene_update(t_scene *scene, const t_input *input);

#endif
