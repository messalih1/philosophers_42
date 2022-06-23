NAME = philo

SRC = main.c header.c init_philos.c get_time.c circle.c  philosophers.c


all: $(NAME)

$(NAME): $(SRC) header.h
	cc -pthread $(SRC) -o $@

clean:
	rm -rf $(NAME)


re: fclean all