/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:17:08 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/12 09:17:10 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*int main(void)
{
    t_list *begin_list = NULL;

    char    *data[4] = {"1", "2", "3", "3"};
    int i = 0;
    while (i < 4)
    {
        ft_lstadd_front(&begin_list, (void *)data[i]);
        printf("%s\n", (char *)begin_list->content);
        i++;
    }
    printf("%d\n", ft_lstsize(begin_list));
    return (0);
}*/
