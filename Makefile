NAME			=	push_swap

SRCS			=	main.c b_to_a.c validation.c validation_utils.c markup.c\
					move_b_to_a.c a_to_b.c initialisation.c commands.c\
					b_to_a_utils.c

SRCS_B			=

HEADER			= push_swap.h

LIBFT			= ./libft/libft.a

GNL = get_next_line.c get_next_line_utils.c


OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc

RM				= @rm -f

FLAGS			= -Wall -Wextra -Werror

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(MAKE) all -C ./libft
				@$(MAKE) bonus -C ./libft
				$(CC) $(OBJ) -I$ {HEADER} ${LIBFT} -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(FLAGS) -I$ {HEADER} -c $< -o $@

bonus:
				make OBJ="$(OBJ_B)" all

clean:			
				@$(MAKE) clean -C ./libft
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				@$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)