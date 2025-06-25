/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:25:10 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/06/25 15:31:45 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* return the number of digits required to represent an unsigned int in hexa */
int	ft_hex_len(unsigned int num)
{
	int	lenght;

	lenght = 0;
	while (num != 0) // loop until all digits are processed
	{
		lenght++;
		num /= 16; // move to the next digit
	}
	return (lenght); // return the number of digits
}

/*  Recursive function to print number in hexadecimal format for l and U */
void	ft_put_hex(unsigned int num, const char specifier)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, specifier);
		ft_put_hex(num % 16, specifier);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
		{
			if (specifier == 'x')
				ft_print_char((num - 10 + 'a')); // print from a to f
			if (specifier == 'X')
				ft_print_char((num - 10 + 'A')); // print from A to F
		}
	}
}

/*  main interface to print the hexadecimal number */
int	ft_print_hex(unsigned int num, const char specifier)
{
	if (num == 0)
		return (ft_print_char('0')); // handle the "0" case
	else
		ft_put_hex(num, specifier); // print the hexa number
	return (ft_hex_len(num));       // return the lenght of
}
/*
int	main(void)
{
	ft_print_hex(255, 'x');
	write(1, "\n", 1);
	ft_put_hex(3735928559, 'X');
	write(1, "\n", 1);
	ft_put_hex(0, 'X');
	printf("\n");
}*/
