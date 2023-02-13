/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/13 16:00:43 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "ft_math.h"

#include <libft.h>

typedef unsigned int t_color;

typedef struct s_vertex
{
	t_float3	position;
	t_color		color;
}	t_vertex; 

typedef struct s_mesh
{
	t_dynarr	vertex_buffer;
	float		width;
	float		height;
	float		depth;
}	t_mesh;

int		mesh_init(t_mesh *mesh);
int		mesh_import(t_mesh *target, const char *filepath);
void	mesh_del(t_mesh *mesh);

void	center_mesh(t_mesh *mesh);

#endif
