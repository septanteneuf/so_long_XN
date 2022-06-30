/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:29:07 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/11 11:50:14 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, const char format)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthexa(n / 16, format);
		count += ft_puthexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + format - ('x' - 'a'));
		count = 1;
	}
	return (count);
}
