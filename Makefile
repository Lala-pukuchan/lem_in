NAME         = lem-in
SRC          = $(addprefix src/, main.c check.c room.c link.c path.c print.c 1_edmondskarp.c ant.c 2_edmondskarp.c 3_edmondskarp.c movement_ant.c 1_outil_for_main.c 2_outil_for_main.c 3_outil_for_main.c)
INCLUDE_DIR  = ./includes
INCLUDE      = -I $(INCLUDE_DIR) -I ./libft
OBJS         = $(SRC:%.c=%.o)
LIBFT        = ./libft/libft.a
CC           = gcc -g -O0
CFLAGS       = -Wall -Werror -Wextra

all     : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(READLINE) $^ $(INCLUDE) -o $@

$(LIBFT):
	make -C libft

clean   : 
	make clean -C libft
	rm -f $(OBJS)

fclean  : clean
	make fclean -C libft
	rm -f $(NAME)

re      : fclean all

.PHONY  : all clean re fclean
