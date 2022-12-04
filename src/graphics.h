/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:26:07 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/04 21:28:27 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

#include "float3.h"

typedef struct s_mesh
{
	t_float3 		*pos;
	unsigned int	*idx;
}	t_mesh;

int		mesh_load(char	*filepath);
void	mesh_destroy(t_mesh *);

// MLX main loop hook. Renders the mesh
int		render_hook(void *param);

#endif
