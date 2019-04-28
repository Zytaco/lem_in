#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/26 16:26:53 by jheeresm      #+#    #+#                  #
#    Updated: 2019/04/26 16:26:53 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = main.c read_and_check.c checks.c distance.c

OBJ = $(SRC:.c=.o)

FLG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC) libft/libft.a
	gcc -c $(FLG) $(SRC)
	gcc $(FLG) $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
