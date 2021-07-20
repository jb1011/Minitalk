NAME = server
NAME2 = client
SRC = server.c
SRC2 = client.c
OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc
	
.PHONY: clean fclean re re-bis
	
all : $(NAME)
	
$(NAME):
	@make -C libft/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
	@$(CC) $(CFLAGS) $(SRC2) -o $(NAME2) -I libft/ -L libft/ -lft

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	
fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	
re: fclean all
