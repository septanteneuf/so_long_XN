/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy@student.42lausanne.ch              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:08:34 by bbourcy           #+#    #+#             */
/*   Updated: 2022/01/11 11:48:25 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

// cs%
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putpc(void);
// diu
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
// ptr
int	ft_puthex(unsigned long long n);
int	ft_ptr(unsigned long long ptr);
// xX
int	ft_puthexa(unsigned int n, const char format);
// printf
int	ft_formats(va_list args, const char *format);
int	ft_printf(const char *s, ...);

#endif
