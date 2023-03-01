/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:49:15 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/11/02 15:34:50 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	i = 0;
	k = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (k[i] != (unsigned char)c)
			i++;
		else
			return (&k[i]);
	}
	return (0);
}
