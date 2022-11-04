# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 18:41:14 by youhan            #+#    #+#              #
#    Updated: 2022/11/04 18:41:44 by youhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
CC = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
SRCS =	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
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