#**************************************************************************** #
#                                                                             #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 15:21:27 by jumiguel          #+#    #+#              #
#    Updated: 2014/11/06 15:33:05 by jumiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_isdigit.c \
		 ft_isalnum.c \
		 ft_memcpy.c \
		 ft_putchar.c \
		 ft_strlcat.c \
		 ft_strncmp.c \
		 ft_tolower.c \
		 ft_atoi.c \
		 ft_isalpha.c \
		 ft_isprint.c \
		 ft_putstr.c \
		 ft_strcpy.c \
		 ft_strlen.c \
		 ft_strncpy.c \
		 ft_toupper.c \
		 ft_bzero.c \
		 ft_isascii.c \
		 ft_memccpy.c \
		 ft_memset.c \
		 ft_strcat.c \
		 ft_strdup.c \
		 ft_strncat.c \
		 ft_strstr.c \
		 ft_strnstr.c \
		 ft_memmove.c \
		 ft_strchr.c \
		 ft_strrchr.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_strcmp.c \
		 ft_memalloc.c \
		 ft_memdel.c \
		 ft_striter.c \
		 ft_striteri.c \
		 ft_strmap.c \
		 ft_strmapi.c \
		 ft_strnew.c \
		 ft_strclr.c \
		 ft_strdel.c \
		 ft_strequ.c \
		 ft_strnequ.c \
		 ft_strsub.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_strsplit.c \
		 ft_putendl.c \
		 ft_putnbr.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 ft_itoa.c \
		 ft_lstnew.c \
		 ft_lstdelone.c \
		 ft_lstdel.c \
		 ft_lstadd.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 arr_size.c \
		 ft_free_arr.c \
		 print_arr.c \
		 ft_putendl_color.c \
		 ft_putstr_color.c \
		 ft_putjoin.c \
		 replace_char.c \
		 ft_intlen.c \
		 print_length.c

OBJECT = $(SOURCE:.c=.o) 

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SOURCE) -I ./includes/
	@ar rc libft.a $(OBJECT) 
	@ranlib libft.a

clean:
	@rm -f $(OBJECT)

fclean: clean 
	@rm -f $(NAME)

re: fclean all

.PHONY: all re name cleam fclean 

