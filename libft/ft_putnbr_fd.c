/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 03:48:48 by sopopa            #+#    #+#             */
/*   Updated: 2022/02/21 04:56:42 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			c = '-';
			write(fd, &c, 1);
			nb *= -1;
			ft_putnbr_fd(nb, fd);
		}
		else if (nb < 10)
		{
			c = nb + '0';
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			c = (nb % 10) + '0';
			write(fd, &c, 1);
		}
	}
}
