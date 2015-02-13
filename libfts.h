/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 14:06:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/02/13 15:14:46 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>

void	ft_bzero(void *s, size_t len);
int		ft_isdigit(int i);
int		ft_isalpha(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_toupper(int i);
int		ft_tolower(int i);
int		ft_strlen(char *str);
int		ft_puts(const char *str);
char	*ft_strcat(char *dest, char *str);
char	*ft_strncat(char *dest, char *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strdup(const char *s);
void	ft_cat(int fd);
void 	*ft_memchr(const void *s, int c, size_t n);


#endif
