/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfind.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 15:18:02 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/22 11:32:49 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#includes "libft.h"

t_list		*ft_lstfind(t_list **alst, void const *content, int len)
{
	t_list		*current;
	int			i;

	if (alst != NULL)
		current = *alst;
	i = 0;
	while (alst != NULL && current != NULL)
	{
		while (i < len && content[i] == current->content[i])
			i++;
		if (i == len)
			return (current);
		current = current->next;
	}
	return (NULL);
}
