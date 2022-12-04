/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:08:27 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/07 08:53:55 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (*dst && dstlen < dstsize)
	{
		dstlen++;
		dst++;
	}
	dstsize -= dstlen;
	return (dstlen + ft_strlcpy(dst, src, dstsize));
}
