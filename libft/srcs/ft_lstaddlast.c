/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddlast.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 11:53:54 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/23 12:50:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list *current;

	if (alst == NULL)
		return (NULL);
	if (*alst == NULL)
	{
		*alst = new;
		return (*alst);
	}
	current = *alst;
	while (current->next != NULL)
		current = current->next;
	if (current->next == NULL)
		current->next = new;
	return (*alst);
}
