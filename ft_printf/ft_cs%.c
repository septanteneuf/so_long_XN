/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs%.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:55:03 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/11 12:00:45 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c affiche un seul caractere
int	ft_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

// %s affiche une chaine de caracteres
int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (count + 6);
	}
	while (s[count])
	{
		count += write(1, &s[count], 1);
	}
	return (count);
}

// %% afiche un pourcentage
int	ft_putpc(void)
{
	int	count;

	count = 0;
	count += write(1, "%", 1);
	return (count);
}
