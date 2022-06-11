NAME = minishell

PROJECT = MINISHELL

SRCS = minishell.c \
		$(addprefix srcs/prompt/, prompt.c) \
		$(addprefix srcs/signals/, signals.c) \
		$(addprefix srcs/parsing/, parsing.c) \
		$(addprefix includes/gnl/, get_next_line.c get_next_line_utils.c) \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes -I./includes/libft/ -I./includes/gnl

GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@gcc $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C includes/libft/
	@gcc $(CFLAGS) $(HEADER) -o $(NAME) -L includes/libft -lft $(SRCS) -lreadline 
	@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

clean:
	@rm -rf $(OBJS) 
	@make clean -C includes/libft
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(NAME)
	@rm -rf includes/libft/libft.a
	@make fclean -C includes/libft
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re
