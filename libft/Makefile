#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/22 17:16:59 by jheeresm      #+#    #+#                  #
#    Updated: 2019/03/01 11:04:16 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libft.a

HDR = libft.h

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c
SRC += ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c
SRC += ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c
SRC += ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c
SRC += ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c
SRC += ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c
SRC += ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c
SRC += ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c
SRC += ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c
SRC += ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c
SRC += ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c
SRC += ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstaddlast.c ft_lstlen.c
SRC += ft_power_of.c ft_lstpop.c ft_greatest.c ft_strnchr.c ft_strnchr2.c
SRC += ft_strrcut.c get_next_line.c
SRCL = $(SRC:%=srcs/%)

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(SRCL)
	@gcc -Wall -Werror -Wextra -c -w $(SRCL)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

cleanmake: $(NAME) clean
