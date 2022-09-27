/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 08:12:40 by mjallada          #+#    #+#             */
/*   Updated: 2022/06/02 08:50:43 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	int	count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count += parameter_gps(*(++str), args); 	
		else
			count += ft_putchar(*str);
		str++;

	}
	va_end(args);
	return (count);
}

int	parameter_gps(char format, va_list args)
{
	unsigned long int	pointer;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbrbase(va_arg(args, int), "0123456789", format));
	else if (format == 'u')
		return (ft_putnbrbase(va_arg(args, unsigned int), "0123456789", format));
	else if (format == 'x' || format == 'X')
		return (ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF", format));
	else if (format == 'p')
	{
		pointer = va_arg(args, unsigned long int);
		if (pointer == 0)
			return (ft_putstr(PTR_NULL));
		write(1, "0x", 2);
		return (ft_putnbrbase(pointer, "0123456789ABCDEF", format) + 2);
	}
	else
		return (ft_putchar(format));
}

int	ft_putnbrbase(long long int nbr, char *base, char format)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;	
	if (nbr < 0)
	{
		count += write (1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < 10)
		count += ft_putchar(nbr + '0');
	else if (nbr < base_len)
	{
		if (format == 'x' || format == 'p')
			count += ft_putchar(nbr - 10 + 'a');
		else if (format == 'X')
			count += ft_putchar(nbr - 10 + 'A');
	}
	else
	{
		count += ft_putnbrbase(nbr / base_len, base, format);
		count += ft_putnbrbase(nbr % base_len, base, format);
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	return(write(1, str, ft_strlen(str)));
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
