# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:17:51 by youhan            #+#    #+#              #
#    Updated: 2022/09/30 02:33:55 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ -std=c++98
NAME = megaphone
CFLAG = -Wall -Werror -Wextra
SRCS = megaphone.cpp
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
	

re: fclean clean

.PHONY : all clean fclean re