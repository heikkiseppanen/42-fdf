/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:16:58 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/06 15:00:47 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "graphics.h"

#include <math.h>

#define ISO_ANGLE 35.264

int		scene_init(t_scene *empty, const char *mesh_path)
{
	ft_printf("Initializing scene with mesh: %s\n ...", mesh_path);
	if (!mesh_from_map(&empty->mesh, mesh_path))
		return (0);
	camera_init(&empty->camera, 90.0, 1);
	empty->cam_transform.position = (t_float3){0.0, 0.0, 1.0}; 
	empty->cam_transform.rotation = (t_float3){0.0, 0.0, 0.0};
	float3_rot_x(&empty->cam_transform.position, ISO_ANGLE * (M_PI / 180));
	float3_rot_y(&empty->cam_transform.position, M_PI / 4);
	empty->mesh_transform.position = (t_float3){0.0, 0.0, 0.0};
	empty->mesh_transform.rotation = (t_float3){0.0, 0.0, 0.0};
	empty->mesh_transform.scale = (t_float3){1.0, 1.0, 1.0};
	return (1);
}

void	scene_del(t_scene *scene)
{
	mesh_del(&scene->mesh);
}

void	scene_update(t_scene *scene, const t_input *input)
{
	t_float3 *cam_pos = &scene->camera_tranform.position;

	if (input->rotate)
		float3_rot_y(&cam_pos, input->mouse_movement.x * input->mouse_sens);
}

