NAME	=	fdf

LIBFT	=	./lib/libft

LIBMLX	=	./lib/MLX42

HEADERS	=	-I ${LIBFT} -I ${LIBMLX}/include

FLAG	=	-Wall -Werror -Wextra -ldl -lglfw -pthread -lm

LIBS	=	${LIBFT}/libft.a ${LIBMLX}/build/libmlx42.a

SRCS	=	./src/main.c \
			./src/draw.c \
			./src/texture.c \
			./src/print_ft.c\
			./src/projection3D.c \
			./src/utils.c \
			./src/init.c \
			./src/check.c\
			./src/free.c \
			./src/keyset.c \
			./src/keyset2.c \
			./src/set_axis.c

HEADER	=	fdf.h

OBJS	=	${SRCS:.c=.o}

all:	${NAME}
		
fl: 	all
		valgrind --leak-check=full --show-leak-kinds=all ./fdf

${NAME}: ${OBJS} Makefile
		@make --no-print-directory -C $(LIBFT)
		cmake ${LIBMLX} -B ${LIBMLX}/build/ && make -C ${LIBMLX}/build -j4
		cc ${OBJS} ${FLAG} ${LIBS} ${HEADERS} -o ${NAME}

%.o: 	%.c $(HEADER)
		cc -o $@ -c $< ${HEADERS}

clean:
		@make --no-print-directory -C $(LIBFT) clean
		@rm -f ${OBJS}

fclean:
		@rm -rf ${LIBMLX}/build
		@make --no-print-directory -C ${LIBFT} fclean
		@rm -f ${OBJS} ${NAME}

re: 	clean all

.PHONY: all clean fclean re