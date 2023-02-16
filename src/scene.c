/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:16:58 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/16 13:50:46 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <math.h>

#define ISO_ANGLE 35.264

static	t_float4x4	calc_scene_matrix(t_scene *source)
{
	const t_float4x4	view = cam_calc_view(&source->camera_transform);
	const t_float4x4	proj = cam_calc_projection(&source->camera);
	const t_float4x4	model = float4x4_model(&source->mesh_transform);
	t_float4x4			scene_matrix;

	scene_matrix = float4x4_mul(&proj, &view);
	scene_matrix = float4x4_mul(&scene_matrix, &model);
	return (scene_matrix);
}

int		scene_init(t_scene *empty, const char *mesh_path)
{
	t_transform *t;;

	ft_printf("Initializing scene with mesh: %s\n ...", mesh_path);
	if (!mesh_import(&empty->mesh, mesh_path))
		return (0);
	cam_init(&empty->camera, M_PI / 2, 1);
	t = &empty->camera_transform;
	t->position = (t_float3){0.0, 0.0, 1.0}; 
	t->position = float3_rot_x(t->position, -ISO_ANGLE * (M_PI / 180));
	t->position = float3_rot_y(t->position, M_PI / 4);
	t->position = float3_scalar(t->position, empty->mesh.width + empty->mesh.height / 2);
	//t->rotation = (t_float3){0.0, ISO_ANGLE * (M_PI / 180), -M_PI / 4};
	t = &empty->mesh_transform;
	t->position = (t_float3){0.0, 0.0, 0.0};
	t->rotation = (t_float3){0.0, 0.0, 0.0};
	t->scale = (t_float3){1.0, 1.0, 1.0};
	empty->scene_matrix = calc_scene_matrix(empty);
	return (1);
}

void	scene_del(t_scene *scene)
{
	mesh_del(&scene->mesh);
}

void	scene_update(t_scene *scene, const t_input *input)
{
	t_float3 *pos = &scene->camera_transform.position;

	scene->camera.orthographic = input->projection_mode;
	if (input->rotate)
	{
		*pos = float3_rot_y(*pos, input->mouse_movement.x * input->mouse_sens);
	}
	if (input->zoom)
	{
		scene->camera.fov += input->mouse_movement.y * input->mouse_sens;
	}
	scene->scene_matrix = calc_scene_matrix(scene);
}

