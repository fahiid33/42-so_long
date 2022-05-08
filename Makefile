# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 15:23:06 by fstitou           #+#    #+#              #
#    Updated: 2022/05/08 16:50:48 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = 

SRC = so_long.c get_next_line.c get_next_line_utils.c map.c\
		utils.c		

		
SRC_BONUS = 


OBJ =   so_long.o get_next_line.o get_next_line_utils.o map.o\
		utils.o
OBJ_BONUS = 

all : $(NAME)

$(NAME):
	
	@gcc $(SRC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "suii 👍👍👍"

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