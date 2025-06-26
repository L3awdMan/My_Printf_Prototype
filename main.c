/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:25:45 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/06/26 20:55:48 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <string.h>

int	main(void)
{
	int		x;
	int		*ptr;
	char	*null_str;

	x = 123;
	ptr = malloc(sizeof(int));
	if (ptr)
		*ptr = 77;
	int ret_std, ret_ft;
	// 1. Simple string + int
	printf(" -- TEST 1 -- Simple string + int\n\n[printf]        : ");
	ret_std = printf("Hello %s, number: %d\n", "world", 42);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]     : ");
	fflush(stdout);
	ret_ft = ft_printf("Hello %s, number: %d\n", "world", 42);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 2. Hex + unsigned
	printf("\n -- TEST 2 -- Hex + unsigned \n\n[printf]       : ");
	ret_std = printf("Hex: %x, Unsigned: %u\n", 305441741, 4294967295u);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("Hex: %x, Unsigned: %u\n", 305441741, 4294967295u);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 3. Pointer with valid address
	printf("\n -- TEST 3 -- Pointer with valid address\n\n[printf]       : ");
	ret_std = printf("Pointer: %p\n", &x);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("Pointer: %p\n", &x);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 4. NULL string
	printf("\n -- TEST 4 -- NULL STRING\n\n[printf]       : ");
	null_str = NULL;
	ret_std = printf("NULL string: %s\n", null_str);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("NULL string: %s\n", NULL);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 5. %p with NULL
	printf(" -- TEST 5 -- Pointer with NULL\n\n[printf]       : ");
	ret_std = printf("NULL ptr: %p\n", NULL);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("NULL ptr: %p\n", NULL);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 6. Lone '%'
	printf(" -- TEST 6 -- Lone Percent\n\n[printf]       : ");
	ret_std = printf("Percent only: UB\n");
	// UB behavior
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("Percent only: % \n"); // Should return -1
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 7. Trailing % after format
	printf(" -- TEST 7 -- Treating percent after format specifier\n\n[printf]       : ");
	ret_std = printf("Trailing percent: %d%%\n", 123); // UB
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("Trailing percent: %d% \n", 123); // Should return -1
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 8. INT_MIN / MAX
	printf(" -- TEST 8 -- INT_MIN / MAX\n\n[printf]       : ");
	ret_std = printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 9. malloc pointer
	printf(" -- TEST 9 -- malloc pointer\n\n[printf]       : ");
	ret_std = printf("malloc ptr: %p\n", ptr);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("malloc ptr: %p\n", ptr);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// 10. Mixed format
	printf(" -- TEST 10 -- Mixed format specifier\n\n[printf]       : ");
	ret_std = printf("Char: %c, Str: %s, Int: %d, Hex: %X, Ptr: %p\n", 'z',
			"test", -1234, 0xdeadbeef, &ret_std);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_std);
	printf("[ft_printf]    : ");
	fflush(stdout);
	ret_ft = ft_printf("Char: %c, Str: %s, Int: %d, Hex: %X, Ptr: %p\n", 'z',
			"test", -1234, 0xdeadbeef, &ret_std);
	fflush(stdout);
	printf("[return: %d]\n\n", ret_ft);
	// Cleanup
	free(ptr);
	return (0);
}
