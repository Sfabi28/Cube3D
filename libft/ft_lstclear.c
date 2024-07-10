/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:16:52 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/12 11:16:54 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_del(void *s)
{
	s = NULL;
}*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}

/*int main(void)
{
    t_list  *a;
    t_list  *b;
    char *strs[4] = {"sndkandlsa", "hfa", "wq", "papa"};
    int i = 1;

    a = ft_lstnew((void *)strs[0]);
    b = a;
    printf("before freeing %s\n", (char *)b->content);
    while (i < 4)
    {
        ft_lstadd_front(&b, (void *)strs[i]);
        a = b->next;
        printf("before freeing %s\n", (char *)b->content);
        i++;
    }
    ft_lstclear(&b, ft_del);
    while (a)
    {
        a = a->next;
        printf("after freeing %s\n", (char *)a->content);
    }
}*/
