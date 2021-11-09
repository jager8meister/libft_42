/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:45:30 by tsidney           #+#    #+#             */
/*   Updated: 2020/11/17 01:03:55 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_lst;
	t_list	*result_elem;

	if (!lst || !f)
		return (NULL);
	if (!(result_elem = ft_lstnew(f((*lst).content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	result_lst = result_elem;
	lst = (*lst).next;
	while (lst)
	{
		if (!(result_elem = ft_lstnew(f((*lst).content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&result_lst, del);
			break ;
		}
		lst = (*lst).next;
		ft_lstadd_back(&result_lst, result_elem);
	}
	return (result_lst);
}
