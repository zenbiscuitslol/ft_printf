/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprejith <pprejith@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:36:52 by pprejith          #+#    #+#             */
/*   Updated: 2025/03/29 20:44:59 by pprejith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int n)
{
	char	num;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		else
			return (11);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n >= 10)
		len += print_num(n / 10);
	num = (n % 10) + '0';
	if (write(1, &num, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	print_unsigned_num(unsigned int n)
{
	char	num;
	int		len;

	len = 0;
	if (n >= 10)
		len += print_num(n / 10);
	num = (n % 10) + '0';
	if (write(1, &num, 1) == -1)
		return (-1);
	len++;
	return (len);
}

static int	hexa_helper(unsigned int n, char *range)
{
	int	num_char;

	num_char = 0;
	if (n >= 16)
		num_char += hexa_helper(n / 16, range);
	if (write(1, &range[n % 16], 1) == -1)
		return (-1);
	num_char++;
	return (num_char);
}

int	print_hexa(unsigned int n, char *range)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (hexa_helper(n, range));
}
