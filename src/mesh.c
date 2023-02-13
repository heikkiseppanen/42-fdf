/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:48:33 by hseppane          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:52 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

#include <libft.h>

#include <fcntl.h>
#include <unistd.h>

#define MAP_READ_CHUNK_SIZE 64
#define MIN_VERTS 4

static int	read_map(t_dynarr *buffer, const char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	ssize_t		read_output;

	read_output = 1;
	while (read_output > 0)
		read_output = dynarr_read(buffer, fd, MAP_READ_CHUNK_SIZE);
	close(fd);
	if (read_output < 0)
	{
		dynarr_del(buffer);
		return (0);
	}
	dynarr_pushback(buffer, "\0", 1);
	return (1);
}

static int parse_map(t_mesh *empty, const t_dynarr *map_data)
{
	const char	*it = map_data->ptr;
	t_vertex	vert;

	empty->width = 0;
	empty->depth = 0;
	while (*it)
	{
		vert.position = (t_float3){empty->width++, ft_atoi(it), empty->depth};
		if (!dynarr_pushback(&empty->vertex_buffer, &vert, 1))
			return (0);
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
	if (empty->vertex_buffer.size % (int)empty->depth != 0)
		return (0);
	empty->width = empty->vertex_buffer.size / empty->depth;
	return (1);
}

int	mesh_import(t_mesh *empty, const char *filepath)
{
	t_dynarr	map_data;

	map_data.ptr = NULL;
	if (!dynarr_init(&map_data, MAP_READ_CHUNK_SIZE, sizeof(char)))
		return (0);
	if (!read_map(&map_data, filepath))
	{
		dynarr_del(&map_data);
		return (0);
	}
	empty->vertex_buffer.ptr = NULL;
	if (!dynarr_init(&empty->vertex_buffer, MIN_VERTS, sizeof(t_float3)))
		return (0);
	if (!parse_map(empty, &map_data))
	{
		dynarr_del(&map_data);
		dynarr_del(&empty->vertex_buffer);
		return (0);
	}
	dynarr_del(&map_data);
	center_mesh(empty);
	return (1);
}

void	mesh_del(t_mesh *mesh)
{
	dynarr_del(&mesh->vertex_buffer);
	mesh->width = 0;
	mesh->height = 0;
	mesh->depth = 0;
}
