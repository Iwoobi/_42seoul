NAME = ex00
CC = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
SRCS =	 main.cpp Dog.cpp Cat.cpp Animal.cpp
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