/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:47:05 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/17 13:42:51 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

static void get_height_values(t_mesh *mesh, float *min, float *max)
{
	const t_float3 *it = mesh->position_buffer.ptr;
	const t_float3 *end = it + mesh->position_buffer.size;

	*min = 0;
	*max = 0;
	while (it != end)
	{
		if (it->y < *min)
			*min = it->y;
		else if (it->y > *max)
			*max = it->y;
		it++;
	}
}

void	calculate_mesh_heat_map(t_mesh *mesh)
{
	float			max;
	float			min;
	int				vertex_count;
	t_float3		*position = mesh->position_buffer.ptr;
	unsigned int	*color = mesh->color_buffer.ptr;

	if (mesh->color_buffer.size != mesh->position_buffer.size
		&& !dynarr_resize(&mesh->color_buffer, mesh->position_buffer.size))
		return ;
	vertex_count = mesh->position_buffer.size;
	get_height_values(mesh, &max, &min); 
	while (vertex_count--)
	{
		if (position->y >= 0)
			*color = 
		else
	}
}

void center_mesh(t_mesh *mesh)
{
	const float	offset_x = (float)(mesh->width - 1) / 2;
	const float	offset_z = (float)(mesh->depth - 1) / 2;
	t_float3	*it;
	t_float3	*end;
	
	it = mesh->position_buffer.ptr;
	end = it + mesh->position_buffer.size;
	while (it != end)
	{
		it->x -= offset_x;
		it->z -= offset_z;
		it++;
	}
}
