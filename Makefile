NAME	=	philo
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall
SRCS	=	init_philos.c main.c utils.c mutex.c philosophers.c

OBJS	=	$(SRCS:.c=.o)

%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all