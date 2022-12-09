/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:48:33 by hseppane          #+#    #+#             */
/*   Updated: 2022/12/09 15:19:18 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

#include <libft.h>

#include <fcntl.h>
#include <unistd.h>

#define MAP_READ_CHUNK_SIZE 64

static parse_map_vertices(

static t_dynarr generate_map_indices(int map_width, int map_height)
{
	t_dynarr	indices;

	if (dynarr_init(&indices, 
	return (indices);
}

// Need to open file (filepath)
// Need to parse the map data line by line (cache height and width?)
int	mesh_from_map(t_mesh *empty, char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	t_dynarr	map_data;
	ssize_t		read_output;
	
	if (dynarr_init(&map_data, MAP_READ_CHUNK_SIZE, 1))
		return (0);
	read_output = 1;
	while (read_output > 0)
		dynarr_read(&map_data, fd, MAP_READ_CHUNK_SIZE);
	if (read_output >= 0)
	{
		
		empty->vertex_arr = g_verts; 
		empty->index_arr = generate_map_indices();
	}
	dynarr_del(&map_data);
	close(fd);
	return (1);
}

void	mesh_destroy(t_mesh *target)
{
	(void) target;
	return ;
}
