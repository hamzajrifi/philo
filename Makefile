NAME = prg.a

CC = gcc

HEADER = philo.h


C_FILES = philo.c\
	  checker.c\
	  utils_functions.c

O_FILES = philo.o

all : 
	$(CC) $(C_FILES) main.c -o  jrifi 

clean :
	rm -f *.o jrifi 