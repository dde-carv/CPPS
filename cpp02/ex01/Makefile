NAME		=	fixed_point_pt2

INC			=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

CC			=	c++ -Wall -Werror -Wextra -std=c++98
RM			=	rm -f

PHONE		=	$(SRC_DIR)main.cpp \
				$(SRC_DIR)Fixed.cpp


SRCS		=	$(PHONE)

OBJS		=	$(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(OBJS) -o $(NAME)
				@echo "\033[1;32m$(NAME) created.\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				@mkdir -p $(@D)
				@$(CC) -I$(INC) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)
			@echo "\033[1;31mObject files deleted.\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[1;31m$(NAME) deleted.\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
