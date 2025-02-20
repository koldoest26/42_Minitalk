NAME = minitalk
SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): all

all: server client

bonus: server_bonus client_bonus

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o libft
	$(CC) -o $@ $< -Llibft -lft

client_bonus: client_bonus.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a

re: fclean all bonus

.PHONY: all bonus libft clean fclean re
