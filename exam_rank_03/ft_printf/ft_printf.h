/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 08:10:11 by mjallada          #+#    #+#             */
/*   Updated: 2022/06/02 08:43:33 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# else
#  define PTR_NULL "(nil)"
# endif

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char *str, ...);
int	parameter_gps(char format, va_list args);
int	ft_putnbrbase(long long int nbr, char *base, char format);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);

#endif

