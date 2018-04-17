# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 14:51:15 by jmlynarc          #+#    #+#              #
#    Updated: 2018/04/17 16:20:51 by jmlynarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
ASSOCIATED_REP = $(NAME).dSYM

LIBFT_REP = libft/
LIBFT = libft/libft.a

INCLUDE_FLAG = -I includes/

SRCS_REP = srcs/
SRCS = $(SRCS_REP)color.c \
	   $(SRCS_REP)draw.c \
	   $(SRCS_REP)exit.c \
	   $(SRCS_REP)julia.c \
	   $(SRCS_REP)keys_event.c \
	   $(SRCS_REP)main.c \
	   $(SRCS_REP)mandelbrot.c \
	   $(SRCS_REP)graphic_manager.c \
	   $(SRCS_REP)move_frame.c \
	   $(SRCS_REP)zoom.c \
	   $(SRCS_REP)burningship.c \
	   $(SRCS_REP)mouse_event.c \
	   $(SRCS_REP)julia_mouse.c

O_SRCS = $(SRCS:.c=.o)

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I ~/Library -g -L ~/Library -lmlx -framework OpenGL -framework \
			AppKit

MULTITHREADING_FLAG = -lpthread

MATH_FLAG = -lm

%.o: %.c
	@gcc $(W_FLAGS) -c $< -o $@

$(NAME):
	make -C $(LIBFT_REP)
	gcc $(INCLUDE_FLAG) $(MLX_FLAGS) $(MATH_FLAG) $(MULTITHREADING_FLAG) \
		$(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_REP)
	rm -rf $(O_SRCS)

fclean: clean
	make fclean -C $(LIBFT_REP)
	rm -rf $(NAME) $(ASSOCIATED_REP)

re: fclean all
