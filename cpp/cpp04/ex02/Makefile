NAME = ex02
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -MMD -std=c++98
SRCS =	main.cpp Animal.cpp Brain.cpp Dog.cpp Cat.cpp 
OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}

-include $(DEPS)

.o : .cpp
	${CC} ${CPPFLAGS} -c $< -o $@
	
${NAME} : ${OBJS}
	${CC} ${CPPFLAGS} -o ${NAME} ${OBJS}

all : ${NAME}

clean :
	rm -f ${OBJS} ${DEPS}
fclean: clean
	rm -f ${NAME}
	

re: fclean all

.PHONY : all clean fclean re