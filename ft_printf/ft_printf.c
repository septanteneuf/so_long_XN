/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:29:22 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/11 11:47:53 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char *format)
{
	int	count;

	count = 0;
	if (format[1] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[1] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[1] == '%')
		count += ft_putpc();
	else if (format[1] == 'd' || format[1] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[1] == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	else if (format[1] == 'p')
		count += ft_ptr(va_arg(args, unsigned long long));
	else if (format[1] == 'x' || format[1] == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), format[1]);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		count;
	char	*str;

	str = (char *)s;
	i = 0;
	count = 0;
	va_start(args, s);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_formats(args, &str[i]);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
