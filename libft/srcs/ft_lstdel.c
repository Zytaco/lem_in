/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 15:42:53 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 12:05:15 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_lstdelone2(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL || *alst == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

void			ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next_one;
	t_list	*current;

	if (*alst != NULL)
		current = alst[0];
	while (*alst != NULL && current->next != NULL)
	{
		next_one = current->next;
		ft_lstdelone2(&current, del);
		current = next_one;
	}
	ft_lstdelone2(&current, del);
	*alst = NULL;
}
