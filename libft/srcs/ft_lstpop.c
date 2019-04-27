/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 10:07:20 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/23 12:59:30 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

static void		ft_lstpop2(t_list **lst, t_list **remove)
{
	if ((*remove)->content != NULL)
	{
		free((*remove)->content);
		(*remove)->content = NULL;
	}
	*lst = (*remove)->next;
	free(*remove);
	*remove = NULL;
}

t_list			*ft_lstpop(t_list **lst, t_list **remove)
{
	t_list *current;

	if (lst == NULL || *lst == NULL || remove == NULL || *remove == NULL)
		return (NULL);
	current = *lst;
	if (current == *remove)
	{
		current = (*remove)->next;
		ft_lstpop2(lst, remove);
		return (current);
	}
	while (current != NULL && current->next != NULL && \
			current->next != *remove)
		current = current->next;
	if (current->next == *remove)
	{
		if ((*remove)->content != NULL)
		{
			free((*remove)->content);
			(*remove)->content = NULL;
		}
		current->next = (*remove)->next;
	}
	return (*lst);
}
