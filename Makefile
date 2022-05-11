# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 15:23:06 by fstitou           #+#    #+#              #
#    Updated: 2022/05/11 23:42:12 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = 

SRC = so_long.c get_next_line.c get_next_line_utils.c map.c\
		utils.c	moves.c 	

		
SRC_BONUS = 


OBJ =   so_long.o get_next_line.o get_next_line_utils.o map.o\
		utils.o moves.o\
OBJ_BONUS = 

all : $(NAME)

$(NAME):
	
	@gcc $(SRC) -fsanitize=address -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "ANKARA MISSII ANKARA MISSII ANKARA MISSII gol gol gol gol"

$(NAME_BONUS) : 
	@gcc -fsanitize=address -Imlx $(SRC_BONUS) -o $(NAME_BONUS)
	@echo "🎁🎁🎁"

bonus: $(NAME_BONUS)

clean :
 
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "🚮🚮🚮"

fclean : clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🗑️ 🗑️ 🗑️"

re : fclean all