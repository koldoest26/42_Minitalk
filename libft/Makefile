NAME = libft.a

FILES = ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_strchr \
	ft_strdup \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_tolower \
	ft_toupper \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_printf \
	ft_printf_utils \


CC = cc
FLAGS = -Wall -Wextra -Werror

CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

OUTN = $(NAME)

NAMES = $(OUTN)

LIB = ar -rcs

$(NAME):
	$(CC) $(FLAGS) -c $(CFILES) -I./
	$(LIB) $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAMES)

re: fclean all

.PHONY: all, clean, fclean, re
