#		Source Files
SRCS	= $(addprefix src/, exit_game.c key_pressed.c validate_map_utils.c validate_map.c \
	parse_map.c render_graphics.c so_long.c init_game.c print_errors.c)
GNL_SRCS	= $(addprefix get_next_line/, get_next_line_utils.c get_next_line.c)

#		Object Files
OBJS	= $(SRCS:.c=.o)
GNL_OBJS	= $(GNL_SRCS:.c=.o)

#		Includes
Includes	= -Iinc -Iget_next_line -Imlx

#		Variables
NAME	= so_long
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

#		Default Target
all:	$(NAME)

# Linking the so_long Executable
$(NAME): ${OBJS} ${GNL_OBJS}
	make -C ft_printf
	cd mlx && ./configure
	$(CC) ${CFLAGS} $(OBJS) $(GNL_OBJS) -Lmlx -lmlx -Lft_printf -lftprintf -lXext -lX11 -lm -lz -o $(NAME)

#		Compilation Rule
%.o: %.c
	$(CC) $(CFLAGS) $(Includes) -c $< -o $@

#		Delete Object Files
clean:
		$(RM) $(OBJS) $(GNL_OBJS)
		make clean -C ft_printf

#		Delete Object Files and Executables
fclean: clean
		make clean -C mlx
		make fclean -C ft_printf
		$(RM) $(NAME)

#		Rebuild Everything
re:	fclean all

.PHONY:	all clean fclean re
