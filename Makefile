# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalmine <msalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/28 11:37:13 by jsankari          #+#    #+#              #
#    Updated: 2020/08/29 19:05:23 by msalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \
	ft_validator.c \
	ft_coordinator.c \
	ft_grid_solver.c \

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : 
	@gcc $(FLAGS) -c $(SRCS) 
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "[ Fillit executable compiled ]"

clean :
	@rm -f $(OBJ)
	@echo "[ Fillit objects deleted ]"

fclean : clean
	@rm -f $(NAME)
	@echo [ Fillit executable deleted ]

re : fclean all

.PHONY = all clean fclean re