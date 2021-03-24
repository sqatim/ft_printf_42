# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqatim <sqatim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 21:39:46 by sqatim            #+#    #+#              #
#    Updated: 2019/12/31 18:58:28 by sqatim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c ft_check.c ft_fonction.c ft_print_fct.c \
		ft_flags.c ft_print_cvr.c ft_determination.c ft_count.c \
		ft_count_fct.c ft_signe.c ft_pos_fct.c ft_print_width.c \
		ft_ntr_fct.c 

SRC_LIB = libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c \
			libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c \
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
			libft/ft_strchr.c libft/ft_strlcat.c libft/ft_strncmp.c \
			libft/ft_tolower.c libft/ft_strdup.c libft/ft_strlen.c \
			libft/ft_strnstr.c libft/ft_toupper.c libft/ft_strrchr.c \
			libft/ft_substr.c libft/ft_strjoin.c libft/ft_putchar_fd.c \
			libft/ft_itoa.c libft/ft_strlcpy.c libft/ft_strtrim.c \
			libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			libft/ft_split.c libft/ft_strmapi.c libft/ft_itoa.c\
			libft/ft_atoi.c libft/ft_bzero.c 
		
OBJ_LIB = $(SRC_LIB:.c=.o)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_LIB) ft_printf.h
	ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJ)
	rm -rf $(OBJ_LIB)

fclean : clean
	rm -rf $(NAME)

re : fclean all

