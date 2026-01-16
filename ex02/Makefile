NAME = PmergeMe

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp

OBJ_SRCS = ${SRCS:.cpp=.o}


all: ${NAME}

${NAME}: ${OBJ_SRCS}
	${CC} ${CPPFLAGS} $^ -o $@

%.o: %.c PmergeMe.hpp
	${CC} ${CPPFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_SRCS}

fclean: clean
	rm -f ${NAME}

re: fclean all