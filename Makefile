NAME = philo

SRC = philo.c struct.c philopthread.c\
	

CC = cc -g
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:%.c=%.o)
BONUS = $(BNS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread
			
clean:
		@$(RM) $(OBJ)
		
fclean: clean
		@$(RM) $(NAME)
		
re: fclean all
