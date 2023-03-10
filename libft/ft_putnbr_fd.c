/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:48:24 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/02/13 13:11:41 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10));
			ft_putchar_fd((n % 10 + '0'));
		}
		else
		{
			ft_putchar_fd((n + '0'));
		}
	}
}
