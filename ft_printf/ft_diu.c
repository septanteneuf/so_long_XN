/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:55:31 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/11 11:54:52 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d imprime un nombre décimal (base 10) et %i imprime un entier en base 10
int	ft_putnbr(int n)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i > 9)
	{
		count += ft_putnbr(i / 10);
		i %= 10;
	}
	ft_putchar(i + '0');
	count++;
	return (count);
}

// %u affiche les unsigned int 
int	ft_putnbr_u(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
	count++;
	return (count);
}
