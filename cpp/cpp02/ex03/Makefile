# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 22:08:36 by youhan            #+#    #+#              #
#    Updated: 2022/11/24 22:26:07 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03
CC = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
SRCS =	 main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = ${SRCS:.cpp=.o}

.o : .cpp
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