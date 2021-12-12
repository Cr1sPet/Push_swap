NAME        =   my_push_swap
LIB_NAME    =   push_swap.a
SRCS    =   push_swap.c is_valid.c\
HEADER  =   push_swap.h
%.o : &.c $(HEADER)
	@$(CC)  $(CFLAGS) -c $< -O $@
OBJ =   $(SRCS:%.c=%.o)
CC      =   gcc
FLAGS   =   -Wall -Werror -Wextra
.PHONY  :   all clean fclean re
all         :   $(NAME)
$(NAME) :   $(OBJ)
	$(MAKE) all -C ./libft
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(LIB_NAME)
	ar rcs $(LIB_NAME) $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(LIB_NAME)
clean   :
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
fclean  :   clean
	$(MAKE) fclean -C ./libft
	rm -f $(LIB_NAME)
re      : fclean all