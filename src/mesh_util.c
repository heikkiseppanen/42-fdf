/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:47:05 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/13 14:47:21 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

void center_mesh(t_mesh *mesh)
{
	const float	offset_x = mesh->width / 2;
	const float	offset_z = mesh->depth / 2;
	t_float3	*it;
	t_float3	*end;
	
	it = mesh->vertex_buffer.ptr;
	end = it + mesh->vertex_buffer.size;
	while (it != end)
	{
		it->x -= offset_x;
		it->z -= offset_z;
		it++;
	}
}
