/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 12:04:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/03 18:30:06 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t len);

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

	return 0;
}
