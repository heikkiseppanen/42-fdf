/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/17 08:46:15 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "ft_math.h"

#include <libft.h>

typedef struct s_mesh
{
	t_dynarr	position_buffer;
	t_dynarr	color_buffer;
	int			width;
	int			depth;
}	t_mesh;

int		mesh_init(t_mesh *mesh);
void	mesh_del(t_mesh *mesh);
int		mesh_import(t_mesh *target, const char *filepath);

void	center_mesh(t_mesh *mesh);

#endif
