SRCS		= src/convert_map.c \
				src/graphic_rendering.c \
				src/main.c \
				src/parsing.c \
				src/utils.c \
				src/utils_1.c \
				src/utils_2.c \
				src/utils_3.c 

OBJS		=	$(SRCS:.c=.o)
NAME		=	so_long
CC		=	gcc -g3
FLAGS		=	-Wall -Wextra -Werror
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM			=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
