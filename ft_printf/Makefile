SRCS	=	ft_abs.c ft_printf.c \
			ft_putaddress.c ft_putchar.c \
			ft_puthexa.c ft_putnbr.c \
			ft_putstr.c ft_putunsigned.c

OBJS	=	${SRCS:.c=.o}

#		Variables		#

NAME	=	libftprintf.a

LIBFTNAME	=	libft.a

AR	=	ar rcs

RM	=	rm -f

CC	= cc

CFLAGS	=	-Wall -Wextra -Werror

LIBFTDIR	=	./libft

#		Rules/Targets		#

all:	${NAME}

makelibft:
		make -C ${LIBFTDIR}
		cp ${LIBFTDIR}/${LIBFTNAME} .
		mv ${LIBFTNAME} ${NAME}

${NAME}:	makelibft ${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}
		cd ${LIBFTDIR} && make clean

fclean:	clean
		${RM} ${NAME}
		cd ${LIBFTDIR} && make fclean
		
re:	fclean all

.PHONY:	all clean fclean re
