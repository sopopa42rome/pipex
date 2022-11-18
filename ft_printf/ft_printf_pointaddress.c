/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointaddress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:35:43 by sopopa            #+#    #+#             */
/*   Updated: 2022/10/23 10:35:27 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_pointaddress(unsigned long long ptr)
{
	int	print_lenght;

	print_lenght = write(1, "0x", 2);
	if (ptr == 0)
		return (2 + write (1, "0", 1));
	else
	{
		ft_print_hex_ptr(ptr);
		print_lenght += ft_print_len(ptr);
	}
	return (print_lenght);
}

void	ft_print_hex_ptr(unsigned long ptr)
{
	if (ptr >= 16)
	{	
		ft_print_hex_ptr(ptr / 16);
		ft_print_hex_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
		{
			ft_putchar_fd((ptr - 10 + 'a'), 1);
		}
	}
}
