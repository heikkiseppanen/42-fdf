/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:59:55 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/29 13:10:37 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window
{
	void	*mlxptr;
	void	*winptr;
	int		width;
	int		height;
} t_window;

int window_init(t_window *win, int width, int height, char *title);
void window_destroy(t_window *win);

#endif
