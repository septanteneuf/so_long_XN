/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:29:17 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/11 11:49:11 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16);
		count += ft_puthex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'x' - ('x' - 'a'));
		count = 1;
	}
	return (count);
}

int	ft_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		count += ft_puthex(ptr);
	return (count);
}
