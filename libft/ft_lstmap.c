/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:27:52 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/12 13:27:54 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*rt;
	t_list	*tmp;

	tmp = lst;
	res = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (tmp)
	{
		rt = ft_lstnew(f(tmp->content));
		if (!rt)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, rt);
		tmp = tmp->next;
	}
	return (res);
}

/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*rt;
	t_list	*tmp;

	tmp = lst;
	res = NULL;
	if (!lst || !del || !f)
		return (NULL);
	while (tmp)
	{
		rt = ft_lstnew(f(tmp->content));
		ft_lstadd_back(&res, rt);
		if (!rt)
			ft_lstdelone(&res, del);
		tmp = tmp->next;
	}
	return (res);
}*/
