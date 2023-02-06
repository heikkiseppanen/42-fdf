/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:54 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/06 14:22:28 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	cam_init(t_cam *empty, float fov, int is_ortho)
{
	empty->fov = fov;
	empty->orthographic = is_ortho;
}
