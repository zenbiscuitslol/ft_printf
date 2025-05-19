/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprejith <pprejith@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:09:37 by pprejith          #+#    #+#             */
/*   Updated: 2025/05/19 16:38:13 by pprejith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(va_list args, char fs)
{
	int	num_char;

	num_char = 0;
	if (fs == 'c')
		return (print_char(va_arg(args, int)));
	if (fs == 's')
		return (print_str(va_arg(args, char *)));
	if (fs == '%')
		return (print_percent());
	if (fs == 'd' || fs == 'i')
		return (print_num(va_arg(args, int)));
	if (fs == 'u')
		return (print_unsigned_num(va_arg(args, unsigned int)));
	if (fs == 'x')
		return (print_hexa(va_arg(args, unsigned int), "0123456789abcdef"));
	if (fs == 'X')
		return (print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (fs == 'p')
		return ((print_ptr(va_arg(args, void *), "0123456789abcdef")));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num_char;
	int		res;
	int		i;

	va_start(args, str);
	num_char = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			res = format_specifier(args, str[++i]);
			if (res == -1)
				return (-1);
		}
		else
		{
			res = print_char(str[i]);
			if (res == -1)
				return (-1);
		}
		num_char += res;
	}
	return (va_end(args), num_char);
}

