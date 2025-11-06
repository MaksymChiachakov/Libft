/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:32:28 by mchiacha          #+#    #+#             */
/*   Updated: 2025/11/06 09:37:52 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*p;

	if (count == 0 || size == 0)
		return (malloc(1));
	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
