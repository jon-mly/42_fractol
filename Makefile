# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 14:51:15 by jmlynarc          #+#    #+#              #
#    Updated: 2018/05/23 11:30:55 by jmlynarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
ASSOCIATED_REP = $(NAME).dSYM

LIBFT_REP = libft/
LIBFT = libft/libft.a

INCLUDE_FLAG = -I includes/

SRCS_REP = srcs/
SRCS = color.c \
		draw.c \
		exit.c \
		julia.c \
		keys_event.c \
		main.c \
		mandelbrot.c \
		graphic_manager.c \
		move_frame.c \
		zoom.c \
		burningship.c \
		mouse_event.c \
		julia_mouse.c

SRC = $(addprefix $(SRCS_REP), $(SRCS))

O_SRCS = $(SRC:.c=.o)

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I ~/Library -g -L ~/Library -lmlx -framework OpenGL -framework \
			AppKit

MULTITHREADING_FLAG = -lpthread

MATH_FLAG = -lm

%.o: %.c
	@gcc $(W_FLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(NAME): $(O_SRCS)
	make -C $(LIBFT_REP)
	gcc $(INCLUDE_FLAG) $(MLX_FLAGS) $(MATH_FLAG) $(MULTITHREADING_FLAG) \
		$(SRC) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_REP)
	rm -rf $(O_SRCS)

fclean: clean
	make fclean -C $(LIBFT_REP)
	rm -rf $(NAME) $(ASSOCIATED_REP)

re: fclean all
