/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:50:50 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/03 09:32:53 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strflds(char const *str, const char delim)
{
	int	fields;

	fields = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str)
		{
			fields++;
			while (*str != delim && *str)
				str++;
		}
	}
	return (fields);
}

static void	*ft_strarr_destroy(char **arr)
{
	char	**it;

	it = arr;
	if (arr)
	{
		while (*it)
		{
			free(*it);
			it++;
		}
		free(arr);
	}
	return (NULL);
}

static size_t	ft_toklen(const char *str, char delim)
{
	const char	*it;

	it = str;
	while (*it != delim && *it)
		it++;
	return (it - str);
}

static void	*ft_tokdup(const char *s, size_t len)
{
	char	*tok;

	tok = malloc((len + 1) * sizeof(*tok));
	if (!tok)
		return (NULL);
	ft_memcpy(tok, s, len);
	tok[len] = '\0';
	return (tok);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	arr_size;
	size_t	tok_len;

	if (!s)
		return (NULL);
	arr_size = ft_strflds(s, c) + 1;
	arr = malloc(arr_size * sizeof(*arr));
	if (!arr)
		return (NULL);
	arr[arr_size - 1] = NULL;
	i = 0;
	while (i < arr_size - 1)
	{
		while (*s == c)
			s++;
		tok_len = ft_toklen(s, c);
		arr[i] = ft_tokdup(s, tok_len);
		if (!arr[i])
			return (ft_strarr_destroy(arr));
		s += tok_len;
		i++;
	}
	return (arr);
}
