/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 16:40:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 12:15:06 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *current;

	if (lst == NULL || f == NULL)
		return (NULL);
	first = f(lst);
	current = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		current->next = f(lst);
		current = current->next;
	}
	current->next = NULL;
	return (first);
}
