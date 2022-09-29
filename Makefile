NAME = prg.a

CC = gcc  #-fsanitize=thread -g3

FLAG = -Wall -Wextra -Werror

HEADER = philo.h


C_FILES = philo.c\
	  checker.c\
	  utils_functions.c

OBJ = $(C_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(HEADER) $(OBJ) main.c
			ar -rc $(NAME) $(OBJ)
			$(CC) $(FLAG)  $(NAME) main.c -o jrifi
clean :
	rm -f *.o 

fclean : clean 
	rm -f jrifi prg.a

re : fclean all

