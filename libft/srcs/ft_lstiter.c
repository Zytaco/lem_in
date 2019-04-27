/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 16:04:00 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 12:05:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *next_one;

	if (lst == NULL || f == NULL)
		return ;
	while (lst->next != NULL)
	{
		next_one = lst->next;
		f(lst);
		lst = next_one;
	}
	f(lst);
}
