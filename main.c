/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:04:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/04 15:07:18 by dsousa           ###   ########.fr       */
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

int main()
{
	char		*str1;
	char		*str2;
	int			i;

	str1 = malloc(sizeof(char) * 5);
	str2 = malloc(sizeof(char) * 5);
	i = 49;
	while (i < 49 + 5)
	{
		str1[i - 49] = (char)i;
		str2[i - 49] = (char)i;
		i++;
	}

	printf("1 : %s --- 2: %s\n", str1, str2);

	ft_bzero((void *)str1, 5);
	bzero((void *)str2, 5);

	str1[0] += 48;
	str1[1] += 48;
	str1[2] += 48;
	str1[3] += 48;
	str1[4] += 48;


	str2[0] += 48;
	str2[1] += 48;
	str2[2] += 48;
	str2[3] += 48;
	str2[4] += 48;

	printf("\n1 : %s --- 2 : %s\n", str1, str2);

	i = -70;
	while ( i <= 290 )
	{
		if (ft_isalpha(i) != isalpha(i))
			printf("OMG--------------ERROR\n");
		// else
		// 	printf("%d\n", isalpha(i));
		i++;
	}

	i = -70;
	while ( i <= 290 )
	{
		if (ft_isdigit(i) != isdigit(i))
			printf("OMG--------------ERROR\n");
		// else
		// 	printf("%d\n", isalpha(i));
		i++;
	}

	i = -70;
	while ( i <= 290 )
	{
		if (ft_isalnum(i) != isalnum(i))
			printf("OMG--------------ERROR\n");
		// else
		// 	printf("%d\n", isalpha(i));
		i++;
	}

	i = -50;
	while ( i <= 250 )
	{
		if (ft_isascii(i) != isascii(i))
			printf("OMG--------------ERROR\n");
		// else
		// 	printf("%d\n", isascii(i));
		i++;
	}

	return 0;
}
