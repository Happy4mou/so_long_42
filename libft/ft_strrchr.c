/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:33:42 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/10/30 15:41:50 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*k;

	len = ft_strlen(str);
	k = (char *)str;
	while (len >= 0)
	{
		if (k[len] == (char)c)
			return (&k[len]);
		else
			len--;
	}
	return (NULL);
}
