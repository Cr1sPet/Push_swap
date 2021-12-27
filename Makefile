NAME			=	push_swap
NAME_B			=	checker

SRCS			=	main.c b_to_a.c validation.c validation_utils.c markup.c\
					move_b_to_a.c a_to_b.c initialisation.c commands.c\
					b_to_a_utils.c utils.c

SRCS_B			=	checker.c validation_utils.c validation.c\
					s_commands.c commands.c g_n_l.c utils.c

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
bonus:			$(NAME_B)

$(NAME):		$(OBJ)
				@$(MAKE) all -C ./libft
				@$(MAKE) bonus -C ./libft
				$(CC) $(OBJ) -I$ {HEADER} ${LIBFT} -o $(NAME)

$(NAME_B):		$(OBJ_B) $(NAME)
				@$(MAKE) all -C ./libft
				@$(MAKE) bonus -C ./libft
				$(CC) $(OBJ_B) -I$ {HEADER} ${LIBFT} -o $(NAME_B)

%.o:			%.c $(HEADER)
				$(CC) -g $(FLAGS) -I$ {HEADER} -c $< -o $@

bonus:			
				

clean:			
				@$(MAKE) clean -C ./libft
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				@$(MAKE) fclean -C ./libft
				$(RM) $(NAME) $(NAME_B)

re:				fclean $(NAME) $(NAME_B)