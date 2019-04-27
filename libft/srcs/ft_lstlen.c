/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 14:10:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/13 15:01:30 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **alst)
{
	int		len;
	t_list	*current;

	if (alst == NULL || *alst == NULL)
		return (0);
	current = *alst;
	len = 1;
	while (current->next != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
