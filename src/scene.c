/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:16:58 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/17 13:12:29 by hseppane         ###   ########.fr       */
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

	ft_printf("Initializing scene with mesh: %s\n", mesh_path);
	if (!mesh_import(&empty->mesh, mesh_path))
	{
		ft_printf("Mesh import error!", mesh_path);
		return (0);
	}
	cam_init(&empty->camera, rad(90), 1);
	t = &empty->camera_transform;
	t->position = (t_float3){0.0, 0.0, 1.0}; 
	t->position = float3_rot_x(t->position, rad(-ISO_ANGLE));
	t->position = float3_rot_y(t->position, rad(45));
	t->position = float3_scalar(t->position, empty->mesh.width);
	empty->camera.far = float3_len(t->position) + empty->mesh.width;
	empty->camera.ortho_size = empty->mesh.width / 2;
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

void	scene_update(t_scene *scene, t_input *input)
{
	cam_update(&scene->camera, &scene->camera_transform, input);
	scene->scene_matrix = calc_scene_matrix(scene);
}

