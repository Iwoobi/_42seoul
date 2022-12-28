NAME = ex02
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS =	main.cpp AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp  ICharacter.cpp IMateriaSource.cpp
OBJS = ${SRCS:.cpp=.o}

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