/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:42 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/06 15:16:51 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
	
# define DEFAULT_FOV 90

typedef struct s_cam
{
	float		fov;
	int			orthographic;
	t_float3	target;
	t_float3	x_axis;
	t_float3	y_axis;
	t_float3	z_axis;
}	t_cam;

void		cam_init(t_cam *empty, float fov, int is_ortho);
t_float4x4	cam_get_view_matrix(t_cam *cam, const t_transform *transform);

#endif
