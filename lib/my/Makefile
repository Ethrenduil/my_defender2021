##
## EPITECH PROJECT, 2021
## Makefile lib
## File description:
## quentin.vandersteene@epitech.eu
##

SRC	= 	is_prime_number.c \
		my_putchar.c \
		my_puterror.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strncmp.c \
		my_strstr.c \
		my_strcmp.c \
		reverse_string.c \
		show_number.c \
		show_string.c \
		is_alphanum.c \
		show_error.c \
		my_swap.c \
		int_tochar.c \
		my_to_number.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all