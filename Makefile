##
## EPITECH PROJECT, 2021
## InfinAdd
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Wextra -Wno-function-declaration
CPPFLAGS	= -I/usr/local/include
LDFLAGS		= -L/usr/local/lib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC 		=	my_runn.c \

OBJ 		= 	my_runn.o \

TARGET		= 	my_runner \

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C ./lib/my
	$(CC) -o $(TARGET) $(OBJ) -L./lib/ -lmy $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	make clean -C ./lib/my

fclean:clean
	rm -rf $(TARGET)

re:fclean all
