# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 22:00:01 by youhan            #+#    #+#              #
#    Updated: 2022/11/25 23:20:04 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
CC = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
SRCS =	main.cpp PhoneBook.cpp
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