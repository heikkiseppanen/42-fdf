/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:17:42 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/15 10:09:19 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
	
# include "ft_math.h"

# define DEFAULT_FOV 90

typedef struct s_cam
{
	int			orthographic;
	float		fov;
	float		aspect;
	float		near;
	float		far;
}	t_cam;

void		cam_init(t_cam *empty, float fov, int is_ortho);
t_float4x4	cam_calc_projection(const t_cam *view);
t_float4x4	cam_calc_view(const t_transform *transform);

#endif
