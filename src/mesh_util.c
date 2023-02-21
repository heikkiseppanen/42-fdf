/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:47:05 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/21 11:45:11 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

static void get_height_values(t_mesh *mesh, float *min, float *max)
{
	const t_vertex *it = mesh->vertex_buffer.ptr;
	const t_vertex *end = it + mesh->vertex_buffer.size;

	*min = 0;
	*max = 0;
	while (it != end)
	{
		if (it->position.y < *min)
			*min = it->position.y;
		else if (it->position.y > *max)
			*max = it->position.y;
		it++;
	}
}

void	calculate_mesh_colors(t_mesh *mesh)
{
	const t_float3	mid_color = {0.30, 0.34, 0.42};
	float			max;
	float			min;
	t_vertex		*it;
	t_vertex		*end;

	get_height_values(mesh, &min, &max); 
	it = mesh->vertex_buffer.ptr;
	end = it + mesh->vertex_buffer.size;
	while (it != end)
	{
		if (it->position.y > 0)
			it->color = float3_lerp(mid_color,
				(t_float3){0.75, 0.38, 0.42}, it->position.y / max);
		else if (it->position.y < 0)
			it->color = float3_lerp(mid_color,
				(t_float3){0, 0, 1}, it->position.y / min);
		else
			it->color = mid_color;
		it++;
	}
}

void center_mesh(t_mesh *mesh)
{
	const float	offset_x = (float)(mesh->width - 1) / 2;
	const float	offset_z = (float)(mesh->depth - 1) / 2;
	t_vertex	*it;
	t_vertex	*end;
	
	it = mesh->vertex_buffer.ptr;
	end = it + mesh->vertex_buffer.size;
	while (it != end)
	{
		it->position.x -= offset_x;
		it->position.z -= offset_z;
		it++;
	}
}
