NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
AR = ar src
LIBFT = ./libft/
LIBRARY = ./libft/libft.a
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS = $(addsuffix .d, $(basename $(OBJS)))
SRC = main.c free.c utils.c lst_utils.c swap.c push.c testeo.c

$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -MMD -I./ $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	@make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -I./ -o $@

-include $(DEPS)

.PHONY : clean fclean re all

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
