NAME			=	push_swap
NAME_B			=	checker

SRCS_FILES		=	main.c b_to_a.c validation.c validation_utils.c markup.c\
					move_b_to_a.c a_to_b.c initialisation.c commands.c\
					b_to_a_utils.c utils.c ./ft/ft_lstadd_back.c ./ft/ft_lstadd_front.c\
					./ft/ft_lstnew.c ./ft/ft_lstsize.c ./ft/ft_split.c ./ft/ft_strjoin.c ./ft/ft_strlen.c\
					./ft/ft_strdup.c ./ft/ft_isdigit.c ./ft/ft_atoi.c ./ft/ft_putendl_fd.c\
					./ft/ft_lstlast.c ./ft/ft_putchar_fd.c ./ft/ft_putstr_fd.c
SRCS_FILES_B	=	checker.c validation_utils.c validation.c\
					s_commands.c commands.c utils.c ./ft/ft_lstadd_back.c ./ft/ft_lstadd_front.c\
					./ft/ft_lstnew.c ./ft/ft_lstsize.c ./ft/ft_split.c ./ft/ft_strjoin.c ./ft/ft_strlen.c\
					./ft/ft_strdup.c ./ft/ft_isdigit.c ./ft/ft_atoi.c ./ft/ft_putendl_fd.c\
					./ft/ft_lstlast.c ./ft/ft_putchar_fd.c ./ft/ft_putstr_fd.c get_next_line/get_next_line.c\
					./ft/ft_strchr.c

SRCS				=	$(addprefix ./src/, $(SRCS_FILES))
SRCS_B				=	$(addprefix ./src/, $(SRCS_FILES_B))

HEADER			= ./includes/

LIBFT			= ./libft/libft.a

OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc

RM				= @rm -f

FLAGS			= -Wall -Wextra -Werror -I${HEADER}

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJ) $(OBJ_B) $(HEADER)
				$(CC) -o $(NAME) $(OBJ)
				$(CC) $(OBJ_B)  -o $(NAME_B) 

$(NAME_B):		$(OBJ_B) ${NAME}
				$(CC) $(OBJ_B)  -o $(NAME_B)

%.o:			%.c $(HEADER)
				$(CC) -g $(FLAGS) -c $< -o $@

bonus:			
				

clean	:	
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@rm -f $(NAME) $(NAME_B)
re		: fclean all

