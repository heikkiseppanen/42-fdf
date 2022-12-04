/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseppane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:14:19 by hseppane          #+#    #+#             */
/*   Updated: 2022/11/03 08:48:08 by hseppane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*it;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	it = new;
	lst = lst->next;
	while (lst)
	{
		it->next = ft_lstnew(f(lst->content));
		if (!it->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		it = it->next;
		lst = lst->next;
	}
	return (new);
}
