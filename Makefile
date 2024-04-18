NAME         = lem-in
SRC          = $(addprefix src/, main.c check.c room.c link.c)
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
