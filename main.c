/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:04:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/13 15:15:06 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "libfts.h"
#include <fcntl.h>

size_t		rand_str(char *s, size_t max_size)
{
	int		i;

	i = 0;
	max_size = rand() % max_size;
	while (i < max_size)
	{
		s[i] = (char)((rand() % 90) + 30);
		i++;
	}
	s[i] = '\0';

	return (max_size);
}

int main(int ac, char *av[])
{
	char		*str1;
	char		*str2;
	char		*test1;
	char		*test2;
	char		*s_cat1;
	char		*s_cat2;
	int			i;
	int			fd;
	size_t		size;
	int			j;
	int			error;
	char		*str;

	int seed = 428645;
	srand(seed);

	ft_puts("********** Tests de la libfts **********\n   Cette chaine s'affiche avec ft_puts\n");

	str1 = malloc(sizeof(char) * 9);
	str2 = malloc(sizeof(char) * 9);
	i = 49;
	while (i < 49 + 9)
	{
		str1[i - 49] = (char)i;
		str2[i - 49] = (char)i;
		i++;
	}

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
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> bzero\n");

	error = 0;
	s_cat1 = malloc(sizeof(char) * 50);
	s_cat2 = malloc(sizeof(char) * 50);
	test1 = malloc(sizeof(char) * 100);
	test2 = malloc(sizeof(char) * 100);
	i = 0;
	while ( i < 1000000 )
	{
		rand_str(s_cat1, 50);
		rand_str(s_cat2, 50);
		test1 = strcpy(test1, s_cat1);
		test2 = strcpy(test2, s_cat1);

		test1 = ft_strcat(test1, s_cat2);
		test2 = strcat(test2, s_cat2);

		if (strcmp(test1, test2))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> strcat\n");


	i = -700000;
	error = 0;
	while ( i <= 2900000 )
	{
		if (ft_isalpha(i) != isalpha(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> isalpha\n");

	i = -700000;
	error = 0;
	while ( i <= 2900000 )
	{
		if (ft_isdigit(i) != isdigit(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> isdigit\n");

	i = -700000;
	error = 0;
	while ( i <= 2900000 )
	{
		if (ft_isalnum(i) != isalnum(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> isalnum\n");

	i = -700000;
	error = 0;
	while ( i <= 2900000 )
	{
		if (ft_isascii(i) != isascii(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> isascii\n");

	i = -700000;
	error = 0;
	while ( i <= 2900000 )
	{
		if (ft_isprint(i) != isprint(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> isprint\n");

	i = -700000;
	error = 0;
	while ( i <= 2900000 )
	{
		if (ft_toupper(i) != toupper(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> toupper\n");

	i = -700000;
	error = 0;
	while ( i <= 250 )
	{
		if (ft_tolower(i) != tolower(i))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> tolower\n");
	free(s_cat1);
	free(s_cat2);

	test1 = malloc(sizeof(char) * 50);
	error = 0;
	i = 0;
	while ( i < 1000000 )
	{
		rand_str(test1, 50);

		if (strlen(test1) != ft_strlen(test1))
			error++;

		memset(test1, 0, 50);
		i++;
	}
	free(test1);
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> strlen\n");

	test1 = malloc(sizeof(char) * 50);
	test2 = malloc(sizeof(char) * 50);
	error = 0;
	i = 0;
	while ( i < 1000000 )
	{
		bzero(test1, 50);
		bzero(test2, 50);

		test2 = ft_memset(test2, i, 50 - (i % 50) + 1);
		test1 = memset(test1, i, 50 - (i % 50) + 1);

		if (strcmp(test1, test2))
			error++;

		i++;
	}
	free(test1);
	free(test2);
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> memset\n");

	test1 = malloc(sizeof(char) * 50);
	test2 = malloc(sizeof(char) * 50);
	error = 0;
	i = 0;
	while ( i < 1000000 )
	{
		bzero(test1, 50);
		bzero(test2, 50);

		size = rand_str(test1, 50);
		test2 = ft_memcpy(test2, test1, size);
		test1 = memcpy(test1, test1, size);

		if (strcmp(test1, test2))
			error++;

		i++;
	}
	free(test1);
	free(test2);
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> memcpy\n");

	test1 = malloc(sizeof(char) * 50);
	error = 0;
	i = 0;
	while ( i < 1000000 )
	{
		rand_str(test1, 50);
		test2 = ft_strdup(test1);

		if (strcmp(test1, test2))
			error++;

		free(test2);
		i++;
	}
	free(test1);
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> strdup\n");

	ft_puts("\n********** Tests fonction bonus **********\n");

	error = 0;
	s_cat1 = malloc(sizeof(char) * 50);
	s_cat2 = malloc(sizeof(char) * 50);
	test1 = malloc(sizeof(char) * 100);
	test2 = malloc(sizeof(char) * 100);
	i = 0;
	while ( i < 1000000 )
	{
		bzero(test1, 100);
		bzero(test2, 100);
		bzero(s_cat1, 50);
		bzero(s_cat2, 50);

		rand_str(s_cat1, 50);
		size = rand_str(s_cat2, 50);
		test1 = strcpy(test1, s_cat1);
		test2 = strcpy(test2, s_cat1);

		test1 = ft_strncat(test1, s_cat2, (size_t)(size + i) % 50);
		test2 = strncat(test2, s_cat2, (size_t)(size + i) % 50);

		if (strcmp(test1, test2))
			error++;
		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> strncat\n");


	char *c;
	char *d;
	i = 1;
	error = 0;
	while (i < 126)
	{
		c = memchr(test1, i, 50);
		d = ft_memchr(test1, i, 50);

		if ( d != c )
			error++;
		else if ( (c != NULL && d != NULL) && strcmp(c, d) )
			error++;

		i++;
	}
	if (error)
		printf("\033[31m%d Error found \033[0m", error);
	else
		printf("\033[32mAll OK \033[0m");
	printf("-----> memchr\n");


	ft_puts("\n********** Tests de ft_cat **********\n");
	fd = open("mytest", O_RDONLY);
	ft_cat(fd);
	close(fd);

	ft_cat(4651);
	ft_cat(-42);

	ft_puts("\n\n\033[34mft_cat lis maintenant l'entré standard, vous pouvez quitter avec ctrl+D\033[0m");
	ft_cat(0);
	return 0;
}
