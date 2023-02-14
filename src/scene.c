/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:16:58 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/14 10:29:17 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <math.h>

#define ISO_ANGLE 35.264

int		scene_init(t_scene *empty, const char *mesh_path)
{
	ft_printf("Initializing scene with mesh: %s\n ...", mesh_path);
	if (!mesh_import(&empty->mesh, mesh_path))
		return (0);
	cam_init(&empty->camera, M_PI / 2, 1);
	empty->camera_transform.position = (t_float3){0.0, 0.0, 1.0}; 
	empty->camera_transform.rotation = (t_float3){0.0, 0.0, 0.0};
	empty->camera_transform.scale = (t_float3){0.0, 0.0, 0.0};
	float3_rot_x(&empty->camera_transform.position, ISO_ANGLE * (M_PI / 180));
	float3_rot_y(&empty->camera_transform.position, M_PI / 4);
	cam_calc_view(&empty->camera, &empty->camera_transform);
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
	t_float3 *cam_pos = &scene->camera_transform.position;

	if (input->rotate)
		float3_rot_y(cam_pos, input->mouse_movement.x * input->mouse_sens);
	cam_calc_view(&scene->camera, &scene->camera_transform);
}

