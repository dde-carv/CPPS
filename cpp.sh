#!/bin/bash

LAST_EX_CREATED=$(ls -d ex* 2>/dev/null | sort -V | tail -n 1)

if [ -z "$LAST_EX_CREATED" ]; then
  NEW_EX="ex00"
else
  NUM_TEMP=$(echo "$LAST_EX_CREATED" | grep -o '[0-9]\+' | tail -n 1)
  NEW_EX=$(printf "ex%02d" $((10#$NUM_TEMP + 1)))
fi

mkdir -p $NEW_EX
cd $NEW_EX
touch Makefile main.cpp

echo -n "NAME		=" >> Makefile

if [ $# -gt 0 ]; then
  echo " $1" >> Makefile
else
  echo "" >> Makefile
fi

echo -n "SRC			= main.cpp"  >> Makefile

i=2
while [ $i -le $# ]; do
  echo -n " ${!i}.cpp" >> Makefile
  touch "${!i}.cpp" "${!i}.hpp"
  let i++
done

echo "" >> Makefile && echo "OBJ_DIR		= objects
OBJS		= \$(addprefix \$(OBJ_DIR)/, \$(SRC:%.cpp=%.o))

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= @rm -rf

all:		\${NAME}
			@echo "Compiling done"

\${NAME}:	\$(OBJS)
			@\$(CC) \$(CPPFLAGS) \$^ -o \$@

\$(OBJ_DIR)/%.o: %.cpp
			@mkdir -p \$(OBJ_DIR)
			@\$(CC) \$(CPPFLAGS) -c \$< -o \$@

clean:
			@\${RM} \$(OBJ_DIR)
			@echo "Objects removed"

fclean:		clean
			@\${RM} \${NAME}
			@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re"  >> Makefile
