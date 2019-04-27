/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 15:23:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/18 14:43:19 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy2(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tempdst;
	const char	*tempsrc;

	tempdst = dst;
	tempsrc = src;
	i = 0;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

t_list		*ft_lstnew(void const *content, size_t cont_size)
{
	t_list	*new;
	void	*temp;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content_size = cont_size;
		temp = (void*)malloc(cont_size);
		if (temp == NULL)
			free(new);
		if (temp == NULL)
			return (NULL);
		ft_memcpy2(temp, content, cont_size);
		new->content = temp;
	}
	new->next = NULL;
	return (new);
}
