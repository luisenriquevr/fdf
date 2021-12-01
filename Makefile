CC		=	gcc

NAME	=	fdf

FLAGS	=	-Wall  -Wextra -g -framework OpenGL -framework AppKit

SRCS	=	libs/get_next_line/get_next_line.c \
			libs/get_next_line/get_next_line_utils.c \
			srcs/main.c \
			srcs/map_parser.c \
			srcs/draw.c \


OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

$(NAME) : $(OBJS)
		$(MAKE) -C libs/libft
		$(MAKE) -C libs/minilibx_macos
		$(CC) $(OBJS) libs/libft/libft.a libs/minilibx_macos/libmlx.a $(FLAGS) -o $(NAME)

all	:	$(NAME)

clean	:
		${RM} $(OBJS)
		$(MAKE) clean -C ./libs/libft
		$(MAKE) clean -C ./libs/minilibx_macos

fclean	: clean
		${RM} $(NAME)
		$(MAKE) fclean -C ./libs/libft
		$(MAKE) clean -C ./libs/minilibx_macos

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
