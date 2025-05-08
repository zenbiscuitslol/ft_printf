/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprejith <pprejith@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:54:30 by pprejith          #+#    #+#             */
/*   Updated: 2025/03/29 20:30:17 by pprejith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_percent(void);
int	print_num(int n);
int	print_unsigned_num(unsigned int n);
int	print_hexa(unsigned int n, char *range);
int	print_ptr(void *ptr, char *range);

#endif