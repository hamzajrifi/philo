NAME = prg.a

CC = gcc   
# -fsanitize=thread -g3

HEADER = philo.h


C_FILES = philo.c\
	  checker.c\
	  utils_functions.c

O_FILES = philo.o

all : 
	$(CC) $(C_FILES) main.c -o  jrifi 

clean :
	rm -f *.o 

fclean : clean 
	rm -f jrifi

re : fclean all