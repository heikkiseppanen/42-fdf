/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:48:33 by hseppane          #+#    #+#             */
/*   Updated: 2023/01/23 15:42:50 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include <libft.h>

#include <fcntl.h>
#include <unistd.h>

#define MAP_READ_CHUNK_SIZE 64
#define MIN_VERTS 4

static t_dynarr	read_map(const char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	ssize_t		read_output;
	t_dynarr	buf;

	buf.ptr = NULL;
	if (!dynarr_init(&buf, MAP_READ_CHUNK_SIZE, sizeof(char)))
	{
		close(fd);
		return (buf);
	}
	read_output = 1;
	while (read_output > 0)
		read_output = dynarr_read(&buf, fd, MAP_READ_CHUNK_SIZE);
	if (read_output >= 0)
		dynarr_pushback(&buf, "", 1);
	close(fd);
	return (buf);
}

static int parse_map(t_mesh *empty, const t_dynarr *map_data)
{
	const char	*it = map_data->ptr;
	t_float3	vert;

	empty->width = 0;
	empty->depth = 0;
	while (*it)
	{
		vert = (t_float3){empty->width, ft_atoi(it), empty->depth};
		if (!dynarr_pushback(&empty->vertex_arr, &vert, 1))
			return (0);
		empty->width++;
		while (*it && *it != '\n' && *it != ' ')
			it++;
		while (*it == ' ')
			it++;
		if (*it == '\n')
		{
			empty->width = 0;
			empty->depth++;
			it++;
		}
	}
	if (empty->vertex_arr.size % empty->depth != 0)
		return (0);
	empty->width = empty->vertex_arr.size / empty->depth;
	return (1);
}

static void center_mesh(t_mesh *mesh)
{
	const float	offset_x = mesh->width / 2;
	const float	offset_z = mesh->depth / 2;
	t_float3	*it;
	t_float3	*end;
	
	it = mesh->vertex_arr.ptr;
	end = it + mesh->vertex_arr.size;
	while (it != end)
	{
		it->x -= offset_x;
		it->z -= offset_z;
		it++;
	}
}

int	mesh_from_map(t_mesh *empty, const char *filepath)
{
	t_dynarr	map_data;

	map_data = read_map(filepath);
	if (!map_data.size)
	{
		dynarr_del(&map_data);
		return (0);
	}
	dynarr_init(&empty->vertex_arr, MIN_VERTS, sizeof(t_float3));
	dynarr_init(&empty->color_arr, MIN_VERTS, sizeof(unsigned int));
	if (!parse_map(empty, &map_data))
	{
		dynarr_del(&map_data);
		return (0);
	}
	dynarr_del(&map_data);
	center_mesh(empty);
	return (1);
}

void	mesh_destroy(t_mesh *mesh)
{
	dynarr_del(&mesh->vertex_arr);
	dynarr_del(&mesh->color_arr);
}
