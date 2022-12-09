/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:48:33 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 10:56:19 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

// TODO File loading
//
t_float3 g_verts[] = {
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 1.0},
	{1.0, 1.0, 1.0}
};

unsigned int g_idx[] = { 0, 1, 3, 2 };

int	mesh_load(t_mesh *empty, char *filepath)
{
	(void) filepath;
	empty->pos = (t_float3){ 0.0, 0.0, 0.0 };
	empty->rot = (t_float3){ 0.0, 0.0, 0.0 };
	empty->vert = g_verts; // TODO REMOVE GLOBAL
	empty->idx = g_idx; // TODO REMOVE GLOBAL
	empty->vert_count = 4; // TODO CALC
	return (1);
}

void	mesh_destroy(t_mesh *target)
{
	(void) target;
	return ;
}
