# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 14:39:21 by iomayr            #+#    #+#              #
#    Updated: 2022/05/28 08:55:27 by iomayr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 

CFLAGS = -g -Wall -Wextra -Werror

SRC_B = ./bonus/check_elements_bonus.c \
			./bonus/checker.c \
			./bonus/ft_split.c \
			./bonus/init_bonus.c \
			./bonus/utiles_bonus.c \
			./bonus/instructiions.c \
			./bonus/instructions2.c \
			./bonus/instructions3.c \

SRC = main.c \
 		utiles_ps.c \
		extra_utiles_ps.c \
		extra_utiles2_ps.c \
		extra_utiles3_ps.c \
		extra_utiles4_ps.c \
  		check_elements.c \
		init.c \
		ft_split.c \
 		instructions.c \
		instructions2.c \
  		algo.c \
  	 	algo2.c \
		algo3.c \
		
OBJ = ${SRC:%.c=%.o}

OBJ_B = ${SRC_B:%.c=%.o}

HDRS = ./bonus/ps_bonus.h \
		push_swap.h \
		
		
		
NAME = push_swap
NAME_B = checker

all: ${NAME}

${NAME}:${OBJ} ${HDRS}
	@gcc ${CFLAGS} ${SRC} -o push_swap
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"
	

bonus: ${OBJ_B} ${HDRS} 
	@${CC} ${CFLAGS} ${SRC_B} -o checker
	@echo "\033[1;32m##########BONUS COMPILED SUCCESSFULY##########\033[0m"
	

clean:
	rm checker
	@rm ${OBJ_B}
	@echo "\033[1;32m##########BONUS CLEANED SUCCESSFULY##########\033[0m"

fclean:
	@rm ${OBJ}
	@rm push_swap
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"

re: fclean all
