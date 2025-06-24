NAME	=	megaphone

CC		=	c++ -Wall -Werror -Wextra -std=c++98
RM		=	rm -f

FILES	=	megaphone.cpp

SRCS	=	$(FILES)

OBJ		=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME)
			@echo "\033[1;32m$(NAME) created.\033[0m"

fclean:
			@$(RM) $(NAME)
			@echo "\033[1;31m$(NAME) deleted.\033[0m"

re:			fclean all

.PHONY:		all fclean re