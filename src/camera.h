/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:42 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/11 17:04:54 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
	
# include "ft_math.h"

# define DEFAULT_FOV 90

typedef struct s_cam
{
	float		fov;
	int			orthographic;
	float		near;
	float		far;
	t_float3	target;
	t_float3	x_axis;
	t_float3	y_axis;
	t_float3	z_axis;
}	t_cam;

void		cam_init(t_cam *empty, float fov, int is_ortho);
t_float4x4	cam_calculate_space(t_cam *cam, const t_transform *transform);

#endif
