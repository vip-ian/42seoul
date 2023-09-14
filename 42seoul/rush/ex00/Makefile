# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangmle2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 15:55:34 by sangmle2          #+#    #+#              #
#    Updated: 2023/09/10 17:59:31 by sangmle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include
NAME = rush-02
OBJDIR = ./srcs
SRCDIR = ./srcs
SRCS = ./srcs/change.c ./srcs/change_func.c ./srcs/ft_func.c ./srcs/main.c ./srcs/put_dict.c ./srcs/put_dict_func.c ./srcs/put_file.c ./srcs/put_file_func.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
rush-02: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJDIR)/*.o
fclean: clean
	rm -rf $(NAME)

re: fclean all

# $(patsubst pattern, replacement, test)
#   공백문자로 각 단어를 구분하며 특정 패턴을 대체함
# $@
# 현재 명령어의 타겟 이름을 나타냄, 위의 명령어에선 rush-02: $(OBJS)의 rush-02
# $^
# 현재 타겟의 의존성 목록을 나타냄, 위의 명령어에선 rush-02: $(OBJS)의 $(OBJS)
# $<
# 현재 타겟의 첫번째 의존성을 나타냄, 위의 명령어에선 $(OBJDIR)/%.o: $(SRCDIR)/%.c의 $(SRCDIR)/%.c
