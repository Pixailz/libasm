/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:14:10 by brda-sil          #+#    #+#             */
/*   Updated: 2024/01/16 23:46:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libasm.h"

int	test_strlen(char *str)
{
	unsigned int real_size = strlen(str);
	unsigned int mine_size = ft_strlen(str);
	int retv = 0;

	if (real_size == mine_size)
		printf("ft_strlen: OK: size\n");
	else
	{
		printf("ft_strlen: KO: size\n");
		retv |= 1;
	}
	return (retv);
}

int	test_strcpy(char *src)
{
	char	buffer[100] = {0};
	char	*ptr;
	int		retv = 0;

	ptr = ft_strcpy(buffer, src);
	if (ptr == buffer)
		printf("ft_strcpy: OK: ptr\n");
	else
	{
		printf("ft_strcpy: KO: ptr\n");
		retv |= 1;
	}
	if (!strcmp(buffer, src))
		printf("ft_strcpy: OK: strcmp\n");
	else
	{
		retv |= 1;
		printf("ft_strcpy: KO: strcmp\n");
	}
	return (retv);
}

int	test_strcmp(char *s1, char *s2, char mode)
{
	int retv = ft_strcmp(s1, s2);
	int r = 0;

	if (mode == 'e' && retv == 0)
		printf("ft_strcmp: OK: retv == 0\n");
	else if (mode == 'l' && retv < 0)
		printf("ft_strcmp: OK: retv < 0\n");
	else if (mode == 'g' && retv > 0)
		printf("ft_strcmp: OK: retv > 0\n");
	else
	{
		printf("ft_strcmp: KO: retv\n");
		r |= 1;
	}
	return (r);
}

int	main(void)
{
	test_strlen("1234");
	test_strcpy("1234");
	test_strcmp("1234", "1234", 'e');
	test_strcmp("1234", "4321", 'l');
	test_strcmp("4321", "1234", 'g');
	return (0);
}
