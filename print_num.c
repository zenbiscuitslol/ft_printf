/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprejith <pprejith@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:36:52 by pprejith          #+#    #+#             */
/*   Updated: 2025/05/19 16:41:37 by pprejith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int n)
{
	char	num;
	int		len;
	int		temp;

	len = 0;
	if (n == -2147483648)
		return(print_str("-2147483648"));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		n = -n;
	}
	if (n >= 10)
	{
		temp = print_num(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	num = (n % 10) + '0';
	if (write(1, &num, 1) == -1)
		return (-1);
	return (len++, len);
}

int	print_unsigned_num(unsigned int n)
{
	char	num;
	int		len;
	int		temp;

	len = 0;
	if (n >= 10)
	{
		temp = print_unsigned_num(n / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	num = (n % 10) + '0';
	if (write(1, &num, 1) == -1)
		return (-1);
	len++;
	return (len);
}

static int	hexa_helper(unsigned int n, char *range)
{
	int	num_char;
	int	temp;

	num_char = 0;
	if (n >= 16)
	{
		temp = hexa_helper(n / 16, range);
		if (temp == -1)
			return (-1);
		num_char += temp;
	}
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
