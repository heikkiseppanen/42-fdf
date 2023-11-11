/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:38:42 by hseppane          #+#    #+#             */
/*   Updated: 2023/11/11 12:11:48 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# define MOUSE_SENSITIVITY 1.0f

# define KEY_EVENTS 0x00000003
# define BUTTON_EVENTS 0x0000F10C
# define MOUSE_EVENTS 0x00000040

enum e_key
{
	KEY_ESCAPE = 0xFF1B,
	KEY_LEFT = 0xFF51,
	KEY_RIGHT = 0xFF53,
	KEY_P = 0x70,
};

enum	e_mouse_button
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 3,
	MOUSE_MID = 2,
	SCROLL_DOWN = 5,
	SCROLL_UP = 4,
};

#endif
