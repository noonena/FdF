# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euleow <euleow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 15:49:19 by euleow            #+#    #+#              #
#    Updated: 2024/12/15 17:05:05 by euleow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SOURCES 		= ft_strlen.c \
				ft_strrchr.c ft_strncmp.c ft_substr.c \
				ft_split.c \
				ft_split_space.c \
				get_next_line1.c get_next_line2.c \
				get_next_line3.c \

HEADERS 		= .

OBJECTS 		= $(SOURCES:.c=.o)


CC				= cc
FLAGS			= -Wall -Werror -Wextra

AR				= ar -rsc

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJECTS)
				$(AR) $(NAME) $(OBJECTS)

%.o:%.c
				$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

clean:
				$(RM) $(OBJECTS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
