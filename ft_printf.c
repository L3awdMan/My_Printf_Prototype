/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:26:47 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/06/24 23:20:31 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(va_list arg, const char the_specifier)
{
	int	printf_len;

	printf_len = 0;
	if (the_specifier == 'c')
		printf_len += ft_print_char(va_arg(arg, int));
	else if (the_specifier == '%')
		printf_len += ft_print_char('%');
	else if (the_specifier == 's')
		printf_len += ft_print_str(va_arg(arg, char *));
	else if (the_specifier == 'd' || the_specifier == 'i')
		printf_len += ft_print_nbr(va_arg(arg, int));
	else if (the_specifier == 'p')
		printf_len += ft_print_hex_ptr()
}

int	ft_printf(const char *str, ...)
{
	int		printf_len;
	int		i;
	va_list	arg;

	i = 0;
	printf_len = 0;
	while (str[i])
	{
		// if there's '%' go check which specifier it is and return printf lenght
		if (str[i] == '%')
		{
			printf_len += ft_specifier()
		}
	}
}
