/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:04:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/04 15:32:05 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t len);
int		ft_isdigit(int i);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);

int main()
{
	char		*str1;
	char		*str2;
	int			i;
	int			error;

	str1 = malloc(sizeof(char) * 5);
	str2 = malloc(sizeof(char) * 5);
	i = 49;
	while (i < 49 + 5)
	{
		str1[i - 49] = (char)i;
		str2[i - 50] = (char)i;
		i++;
	}

	ft_bzero((void *)str1, 5);
	bzero((void *)str2, 5);

	error = 0;
	i = 0;
	while (i < 5)
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

	return 0;
}
