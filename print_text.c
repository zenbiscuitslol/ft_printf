/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprejith <pprejith@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:16:12 by pprejith          #+#    #+#             */
/*   Updated: 2025/03/29 20:47:32 by pprejith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_null(void)
{
	char	*str;
	int		i;

	i = 0;
	str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (6);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_null());
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
