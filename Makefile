# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 16:20:10 by aaudiber          #+#    #+#              #
#    Updated: 2016/10/27 21:31:34 by aaudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SRC = ./src/FdF.c\
	  ./src/get_line.c\
	  ./src/create_map.c\
	  ./src/get_ynext.c\
	  ./src/err_func.c\
	  ./src/new_link.c\
	  ./src/iso_map.c\
	  ./src/get_max.c\
	  ./src/print_seg.c

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@make -C ./libft
	@make -C ./mlx
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I./libft/includes/ ./libft/libft.a -L/usr/lib -l mlx -framework OpenGL -framework Appkit
	@/bin/echo "---Done---"

clean:
	@/bin/echo "-----cleaning-----"
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/echo "-----fcleaning-----"
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
