# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 18:57:21 by youhan            #+#    #+#              #
#    Updated: 2022/11/14 21:31:15 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
CC = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
SRCS =	main.cpp Zombie.cpp zombieHorde.cpp
OBJS = ${SRCS:.cpp=.o}

.o : .c
	${CC} ${CFLAGS} -c $< -o $@
	
${NAME} : ${OBJS} ${MLX}
	${CC} ${CFLAG} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
	

re: fclean all

.PHONY : all clean fclean re