# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 15:12:03 by dsousa            #+#    #+#              #
#    Updated: 2015/02/12 13:57:00 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		Makefile.sources

NAME		=	libfts.a

CFLAGS		=	-f macho64

OBJ_LIB		=	$(SRC_LIB:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJ_LIB)
	@ar -rc $(NAME) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"Compilation of libfts.a : "\033[32m"Success"\033[0m"


%.o:		%.s
	@echo -n .
	@nasm $(CFLAGS) -s $< -o $@

clean:
	@echo "\033[31m"Objects of libfts.a : deleted"\033[0m"
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@echo "\033[31m"libft.a : deleted"\033[0m"
	@/bin/rm -f $(NAME)

re:			fclean all

test:		re
	@gcc -Wl,-no_pie $(NAME) main.c
	@./a.out


.PHONY:		all re fclean clean test
