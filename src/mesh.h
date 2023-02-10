/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/09 10:14:15 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "libft.h"

typedef struct s_mesh
{
	t_dynarr	vertex_arr;
	//t_dynarr	color_arr;
	float		width;
	float		height;
	float		depth;
}	t_mesh;

int		mesh_from_map(t_mesh *empty, const char *filepath);
void	mesh_del(t_mesh *mesh);

#endif
