NAME				= cub3d
CC					= gcc
CFLAGS				= -march=native -ffast-math -Wall -Werror -Wextra
SRCS				=	main.c						\
						srcs/draw/textures.c		\
						srcs/draw/utils.c			\
						srcs/vector/v2.c			\
						srcs/init.c					\
						srcs/parsing/parse.c		\
						srcs/parsing/check.c		\
						srcs/parsing/parse_map.c	\
						srcs/parsing/parse_tex.c	\
						srcs/parsing/parse_colors.c	\
						srcs/parsing/utils.c		\
						srcs/parsing/utils2.c		\
						srcs/raycasting/ray.c		\
						srcs/raycasting/utils.c 	\
						srcs/dial_key.c				\
						srcs/utils.c

OBJS				= ${SRCS:.c=.o}
OBJS_DIR			= objs/
OBJS_PREFIXED		= $(addprefix $(OBJS_DIR), $(OBJS))

RM					= rm -rf

$(OBJS_DIR)%.o: %.c incl/cub3d.h libft/libft.a mlx/libmlx.a Makefile incl/key_map_azerty.h incl/key_map_qwerty.h
	mkdir -p $(OBJS_DIR)
	mkdir -p $(OBJS_DIR)/srcs
	mkdir -p $(OBJS_DIR)/srcs/parsing
	mkdir -p $(OBJS_DIR)/srcs/draw
	mkdir -p $(OBJS_DIR)/srcs/raycasting
	mkdir -p $(OBJS_DIR)/srcs/vector
	${CC} ${CFLAGS} -c $< -o $@
	printf	"\033[2K\r\033[0;33m[BUILD - $(NAME)]\033[0m $<\e[0m"

all: mlx libft $(NAME)

mlx:
	make -C mlx

libft:
	make -C libft

$(NAME): $(OBJS_PREFIXED) 
	$(CC) $(OBJS_PREFIXED) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L libft -l ft -o $(NAME)
	printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)\n\e[0m"

clean :
	make -C libft clean
	make -C mlx clean
	${RM} $(OBJS_DIR)
	printf "\033[2K\r\033[0;31m.o files deleted.\n\e[0m"

fclean : clean
	make -C libft fclean
	${RM} ${NAME}
	printf "\033[0;31m$(NAME) deleted.\n\e[0m"

re: fclean all

.PHONY : libft mlx all clean fclean re

.SILENT :
