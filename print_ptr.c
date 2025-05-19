/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprejith <pprejith@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:44:27 by pprejith          #+#    #+#             */
/*   Updated: 2025/05/19 15:25:50 by pprejith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_helper_sizet(size_t n, char *range)
{
	int	num_char;

	num_char = 0;
	if (n >= 16)
		num_char += hexa_helper_sizet(n / 16, range);
	if (write(1, &range[n % 16], 1) == -1)
		return (-1);
	num_char++;
	return (num_char);
}

int	print_ptr(void *ptr, char *range)
{
	size_t	ptr1;
	int		num_char;
	int		hexa;

	hexa = 0;
	num_char = 0;
	ptr1 = (size_t)ptr;
	if (!ptr1)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	num_char += 2;
	hexa += hexa_helper_sizet(ptr1, range);
	if (hexa == -1)
		return (-1);
	num_char += hexa;
	return (num_char);
}
