# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: startagl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:20:56 by startagl          #+#    #+#              #
#    Updated: 2023/04/20 14:50:54 by startagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo
SRC =		main.c srcs/thread.c srcs/actions.c srcs/init.c \
			include/utils/atoi.c include/utils/utils.c \
			
OBJ = ${SRC:.c=.o}
FLAGS = -pthread -Wall -Werror -Wextra
GCC = gcc -g

.c.o:
	@${GCC} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	@$(GCC) $(FLAG) $(OBJ) -o $(NAME)
	
all: ${NAME}

clean:
	@rm -f $(OBJ)
	
fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY : clean fclean re all