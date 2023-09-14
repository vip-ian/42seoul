# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 11:59:17 by sangmle2          #+#    #+#              #
#    Updated: 2023/09/12 16:33:25 by sangmle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
INDIR = includes
OBJDIR = srcs

TARGET = ft_atoi.o ft_op.o ft_func.o do_op.o
OBJS = ${addprefix $(OBJDIR)/, $(TARGET)}
NAME = do-op

%.o : %.c
	${CC} ${FLAGS} -c $< -o $@ -I $(INDIR)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) main.c -o $(NAME) $(OBJS) -I $(INDIR)
