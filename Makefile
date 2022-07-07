NAME	=	push_swap
NAME2	=	checker

SRCS	=	arg_handling.c	arg_handling_2.c	sorting_main.c\
			lists_commands.c	list_commands_2.c	list_commands_3.c\
			push_commands.c	swap_commands.c		rotate_commands.c\
			rev_rotate_commands.c	sort_cmds.c	sorting_big.c
SRCS2 	=	for_checker/push_commands_ch.c	for_checker/rotate_commands_ch.c\
			for_checker/rev_rot_ch.c	for_checker/swap_commands_ch.c\
			checker.c
SRCS3	=	push_swap.c

HEADER	=	push_swap.h
OBJ		=	$(SRCS:%.c=%.o)
OBJ2	=	$(SRCS2:%.c=%.o)
OBJ3	=	$(SRCS3:%.c=%.o)
CC		=	gcc
LIB		=	libft/libft.a

INCLUDE	=	-I

FLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re checker libft

all		:	libft $(NAME)

libft	:
			@$(MAKE) -C libft/

$(NAME)	:	$(OBJ) $(OBJ3) $(HEADER)
				$(CC) $(FLAGS) $(OBJ) $(OBJ3) $(LIB) -o $(NAME)

checker	:	$(NAME2)

$(NAME2)	:	$(OBJ)	$(OBJ2) $(HEADER)
				$(CC) $(FLAGS) $(OBJ) $(OBJ2)  $(LIB) -o $(NAME2)

%.o		: %.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			@make clean -C ./libft
			@rm -rf $(OBJ) $(OBJ2) $(OBJ3)

fclean	:	clean
				@make clean -C ./libft
				@$(RM) $(NAME) $(NAME2)

re		:	fclean all