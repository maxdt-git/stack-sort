# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:42:33 by mde-nas           #+#    #+#              #
#    Updated: 2026/05/13 18:59:59 by mde-nas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRCS =  push_swap.c \
        utils/utils.c \
        utils/utils_main.c \
        utils/disorder_metric.c \
        utils/print_bench.c \
        functions_sort/functions_push.c \
        functions_sort/functions_rotate.c \
        functions_sort/functions_reverse_rotate.c \
        functions_sort/functions_swap.c \
        algo/simple_algo.c \
        algo/sort_five.c \
        algo/medium_algo.c \
        algo/adaptive_algo.c \
        algo/complex_algo.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) args100.txt results100.txt args500.txt results500.txt

re: fclean all

test100simple: CFLAGS += -g3
test100simple: $(NAME)
	@shuf -i 0-9999 -n 100 > args100.txt
	@valgrind -q --leak-check=full ./push_swap --bench --simple $$(cat args100.txt) > results100.txt
	@cat results100.txt | ../checker/ubuntu_checker $$(cat args100.txt)

test500simple: CFLAGS += -g3
test500simple: $(NAME)
	@shuf -i 0-9999 -n 500 > args500.txt
	@valgrind -q --leak-check=full ./push_swap --bench --simple $$(cat args500.txt) > results500.txt
	@cat results500.txt | ../checker/ubuntu_checker $$(cat args500.txt)

test100medium: CFLAGS += -g3
test100medium: $(NAME)
	@shuf -i 0-9999 -n 100 > args100.txt
	@valgrind -q --leak-check=full ./push_swap --bench --medium $$(cat args100.txt) > results100.txt
	@cat results100.txt | ../checker/ubuntu_checker $$(cat args100.txt)

test500medium: CFLAGS += -g3
test500medium: $(NAME)
	@shuf -i 0-9999 -n 500 > args500.txt
	@valgrind -q --leak-check=full ./push_swap --bench --medium $$(cat args500.txt) > results500.txt
	@cat results500.txt | ../checker/ubuntu_checker $$(cat args500.txt)

test100complex: CFLAGS += -g3
test100complex: $(NAME)
	@shuf -i 0-9999 -n 100 > args100.txt
	@valgrind -q --leak-check=full ./push_swap --bench --complex $$(cat args100.txt) > results100.txt
	@cat results100.txt | ../checker/ubuntu_checker $$(cat args100.txt)

test500complex: CFLAGS += -g3
test500complex: $(NAME)
	@shuf -i 0-9999 -n 500 > args500.txt
	@valgrind -q --leak-check=full ./push_swap --bench --complex $$(cat args500.txt) > results500.txt
	@cat results500.txt | ../checker/ubuntu_checker $$(cat args500.txt)

test100adaptive: CFLAGS += -g3
test100adaptive: $(NAME)
	@shuf -i 0-9999 -n 100 > args100.txt
	@valgrind -q --leak-check=full ./push_swap --bench --adaptive $$(cat args100.txt) > results100.txt
	@cat results100.txt | ../checker/ubuntu_checker $$(cat args100.txt)

test500adaptive: CFLAGS += -g3
test500adaptive: $(NAME)
	@shuf -i 0-9999 -n 500 > args500.txt
	@valgrind -q --leak-check=full ./push_swap --bench --adaptive $$(cat args500.txt) > results500.txt
	@cat results500.txt | ../checker/ubuntu_checker $$(cat args500.txt)

.PHONY: all clean fclean re
