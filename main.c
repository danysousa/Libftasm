/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:04:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/12 18:50:36 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "libfts.h"
#include <fcntl.h>

int main()
{
	char		*str1;
	char		*str2;
	char		*test;
	int			i;
	int			error;
	int			fd;


	char		*str;

	str = ft_strdup("This is string.h library function");
	ft_puts(str);

	ft_memset(str,'$',7);

	test = malloc(sizeof(char) * 50);
	str1 = malloc(sizeof(char) * 9);
	str2 = malloc(sizeof(char) * 9);
	i = 49;
	while (i < 49 + 9)
	{
		str1[i - 49] = (char)i;
		str2[i - 49] = (char)i;
		test[i - 49] = (char)i;
		i++;
	}

	printf("%s\n", test);
	test = ft_strcat(test, str1);
	printf("%s\n", test);
	// test = strcat(test, str1);
	// printf("%s\n", test);
	test = ft_memcpy(test, "aaass", 5);
	puts(test);

	error = 0;
	if ( ft_strlen(str1) != strlen(str1) )
	{
		printf("ft: %d != %d\n", ft_strlen(str1), strlen(str1) );
		error++;
	}

	printf("%d Error found -----> strlen\n", error);

	ft_puts(str1);
	ft_puts("\n");
	puts(str1);

	ft_bzero((void *)str1, 5);
	bzero((void *)str2, 5);

	error = 0;
	i = 0;
	while (i < 10)
	{
		if (str1[i] != str2[i])
			error++;
		i++;
	}
	printf("%d Error found -----> bzero\n", error);

	i = -70;
	error = 0;
	while ( i <= 290 )
	{
		if (ft_isalpha(i) != isalpha(i))
			error++;
		i++;
	}
	printf("%d Error found -----> isalpha\n", error);

	i = -70;
	error = 0;
	while ( i <= 290 )
	{
		if (ft_isdigit(i) != isdigit(i))
			error++;
		i++;
	}
	printf("%d Error found -----> isdigit\n", error);

	i = -70;
	error = 0;
	while ( i <= 290 )
	{
		if (ft_isalnum(i) != isalnum(i))
			error++;
		i++;
	}
	printf("%d Error found -----> isalnum\n", error);

	i = -50;
	error = 0;
	while ( i <= 250 )
	{
		if (ft_isascii(i) != isascii(i))
			error++;
		i++;
	}
	printf("%d Error found -----> isascii\n", error);


	i = -50;
	error = 0;
	while ( i <= 250 )
	{
		if (ft_isprint(i) != isprint(i))
			error++;
		i++;
	}
	printf("%d Error found -----> isprint\n", error);

	i = -50;
	error = 0;
	while ( i <= 250 )
	{
		if (ft_toupper(i) != toupper(i))
			error++;
		i++;
	}
	printf("%d Error found -----> toupper\n", error);

	i = -50;
	error = 0;
	while ( i <= 250 )
	{
		if (ft_tolower(i) != tolower(i))
			error++;
		i++;
	}
	printf("%d Error found -----> tolower\n", error);


	fd = open("mytest", O_RDONLY);
	ft_cat(fd);

	close(fd);

	ft_cat(4651);
	ft_cat(0);
	return 0;
}
