NAME = libft.a
BNAME = .bonus
OBJ_DIR = ./obj/
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_atoi.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJS_BONUS = $(addprefix $(OBJ_DIR), $(SRCS_BONUS:.c=.o))

DEPS = $(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: %.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -MMD -I./ $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar src $(NAME) $(OBJS)

-include $(DEPS)

bonus: $(BNAME)
	
$(BNAME) : $(OBJS) $(OBJS_BONUS)
	ar src $(NAME) $(OBJS) $(OBJS_BONUS)
	touch $@

.PHONY: clean fclean re all bonus

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all
