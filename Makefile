##
## EPITECH PROJECT, 2020
## myhunter
## File description:
## makefile
##

SRC	= 	./src/main.c \
		./src/window_img.c \
		./src/window.c \
		./src/menu_event.c \
		./src/menu_event2.c \
		./src/draw.c \
		./src/draw2.c \
		./src/config_sprite.c \
		./src/config_sprite2.c \
		./src/option_event.c \
		./src/option_event2.c \
		./src/escape_event.c \
		./src/escape_event2.c \
		./src/game_event.c \
		./src/game_event2.c \
		./src/game_event3.c \
		./src/reset_ui.c \
		./src/enemy.c \
		./src/enemy2.c \
		./src/checks.c \
		./src/texts.c \
		./src/free.c \
		./src/change_options.c \
		./src/change_options2.c

OBJ = $(SRC:.c=.o)

NAME	=	my_defender

OBJ	=       $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -L lib/my -lmy

clean :
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean : clean
	@make clean
	@rm -f $(NAME)
	@make -C ./lib/my fclean

re :	clean all