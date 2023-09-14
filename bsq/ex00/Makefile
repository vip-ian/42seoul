SRCS	= srcs/main.c srcs/algorithms.c srcs/standard_input.c srcs/tool.c srcs/str_function.c srcs/parse.c srcs/parse_func.c
OBJS	= $(SRCS:.c=.o)
NAME	= bsq
INCL	= includes

.c.o :
	gcc -g -c -Wall -Werror -Wextra $< -o $(<:.c=.o) -I $(INCL)

$(NAME) : $(OBJS)
	gcc -g -Wall -Werror -Wextra -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: 
	./perl_map_generator.pl > test