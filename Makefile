CC		=	gcc

NAME	=	fdf

FLAGS	=	-Wall  -Wextra -g -framework OpenGL -framework AppKit

SRCS	=	fdf.c \
			srcs/init.c \
			srcs/map_parser.c \
			srcs/manager.c \
			srcs/image.c \
			srcs/bresenham.c \
			srcs/camera.c \
			libs/custom-libft/ft_split.c \
			libs/custom-libft/get_next_line.c \
			libs/custom-libft/mem_functions.c \
			libs/custom-libft/number_functions.c \
			libs/custom-libft/str_functions.c \

SRCS_BONUS	=	fdf.c \
				srcs_bonus/init_bonus.c \
				srcs_bonus/map_parser_bonus.c \
				srcs_bonus/manager_bonus.c \
				srcs_bonus/image_bonus.c \
				srcs_bonus/bresenham_bonus.c \
				srcs_bonus/camera_bonus.c \
				srcs_bonus/movement_bonus.c \
				libs/custom-libft/ft_split.c \
				libs/custom-libft/get_next_line.c \
				libs/custom-libft/mem_functions.c \
				libs/custom-libft/number_functions.c \
				libs/custom-libft/str_functions.c \

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

RM		=	rm -f

$(NAME) : $(OBJS)
		$(MAKE) -C libs/minilibx-Darwin
		$(CC) $(OBJS) libs/minilibx-Darwin/libmlx.a $(FLAGS) -o $(NAME)

bonus : $(OBJS_BONUS)
		$(MAKE) -C libs/minilibx-Darwin
		$(CC) $(OBJS_BONUS) libs/minilibx-Darwin/libmlx.a $(FLAGS) -o $(NAME)

all	:	$(NAME)

clean	:
		${RM} $(OBJS) $(OBJS_BONUS)
		$(MAKE) clean -C ./libs/minilibx-Darwin

fclean	: clean
		${RM} $(NAME)
		$(MAKE) clean -C ./libs/minilibx-Darwin

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
