NAME = libftprintf.a

SRC = ft_printf.c		\
		hand_dec.c		\
		hand_unsigned.c	\
		unrelated.c		\
		hand_adress.c	\
		hand_str.c		\
		manage_fill_info.c	\
		work_info.c		\
		hand_hex.c		\
		unrelated1.c	\

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

bonus:

clean:
	rm -f *.o

fclean:clean
	rm -f $(NAME)

re:fclean all
