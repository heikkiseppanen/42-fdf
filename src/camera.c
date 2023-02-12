/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:54 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/11 17:13:17 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_init(t_cam *empty, float fov, int is_ortho)
{
	empty->fov = fov;
	empty->orthographic = is_ortho;
	empty->near = 0.1;
	empty->far = 100;
	empty->target = (t_float3){0.0, 0.0, 0.0};
	empty->x_axis = (t_float3){1.0, 0.0, 0.0};
	empty->y_axis = (t_float3){0.0, 1.0, 0.0};
	empty->z_axis = (t_float3){0.0, 0.0, -1.0};
}
