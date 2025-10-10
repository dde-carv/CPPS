#!/bin/bash

# Prompt the user for the CPP directory name
read -p "What cpp am I? " CPP_DIR

# Check if the CPP directory exists
if [ -d "$CPP_DIR" ]; then
  echo "Entering existing directory: $CPP_DIR"
  cd "$CPP_DIR"

  # Find the last exercise directory
  LAST_EX=$(ls -d ex* 2>/dev/null | sort -V | tail -n 1)

  if [ -z "$LAST_EX" ]; then
    # If no exercise exists, create ex00
    echo "No exercises found. Creating ex00..."
    mkdir ex00
    cd ex00
  else
    # Increment the last exercise number
    NUM=$(echo "$LAST_EX" | grep -o '[0-9]\+')
    NEW_EX=$(printf "ex%02d" $((10#$NUM + 1)))
    echo "Creating new exercise: $NEW_EX"
    mkdir "$NEW_EX"
    cd "$NEW_EX"
  fi
else
  # Create the CPP directory and ex00
  echo "Directory $CPP_DIR does not exist. Creating it with ex00..."
  mkdir -p "$CPP_DIR/ex00"
  cd "$CPP_DIR/ex00"
fi

# Create the Makefile, src directory, and inc directory
mkdir -p src inc
touch Makefile

# Populate the Makefile with a basic structure
cat <<EOL > Makefile
NAME		=

INC_DIR		=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

CXX			=	c++ -Wall -Werror -Wextra -std=c++98
RM			=	rm -f

SRCS			=	\$(SRC_DIR)main.cpp

OBJS			=	\$(patsubst \$(SRC_DIR)%.cpp,\$(OBJ_DIR)%.o,\$(SRCS))

all:			\$(NAME)

\$(NAME):		\$(OBJS)
				@\$(CXX) \$(OBJS) -o \$(NAME)
				@echo "\033[1;32m\$(NAME) created.\033[0m"

\$(OBJ_DIR)%.o:	\$(SRC_DIR)%.cpp
				@mkdir -p \$(@D)
				@\$(CXX) -I\$(INC_DIR) -c \$< -o \$@

clean:
			@\$(RM) -r \$(OBJ_DIR)
			@echo "\033[1;31mObject files deleted.\033[0m"

fclean:		clean
			@\$(RM) \$(NAME)
			@echo "\033[1;31m\$(NAME) deleted.\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
EOL

echo "Makefile, src, and inc directories created successfully."

# Function to create a class
create_class() {
  local CLASS_NAME=$1
  local HPP_FILE="inc/${CLASS_NAME}.hpp"
  local CPP_FILE="src/${CLASS_NAME}.cpp"

  # Populate the .hpp file
  cat <<EOL > "$HPP_FILE"
#pragma once

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RST "\033[0m"

#include <iostream>

class $CLASS_NAME
{
	private:
		// Add private attributes here

	public:
		$CLASS_NAME();
		$CLASS_NAME(/* Add parameters here */);
		$CLASS_NAME(const $CLASS_NAME &other);
		$CLASS_NAME	&operator=(const $CLASS_NAME &other);
		~$CLASS_NAME();

		// Add member functions here
};
EOL

  # Populate the .cpp file
  cat <<EOL > "$CPP_FILE"
#include "${CLASS_NAME}.hpp"

/************ Constructors and Destructor ************/

$CLASS_NAME::$CLASS_NAME()
{
	std::cout << GREEN << "$CLASS_NAME default constructor called." << RST << std::endl;
}

$CLASS_NAME::$CLASS_NAME(/* Add parameters here */)
{
	std::cout << GREEN << "$CLASS_NAME custom constructor called." << RST << std::endl;
}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &other)
{
	std::cout << GREEN << "$CLASS_NAME copy constructor called." << RST << std::endl;

	*this = other;
}

$CLASS_NAME &$CLASS_NAME::operator=(const $CLASS_NAME &other)
{
	if (this != &other)
	{
		// Copy attributes here
	}

	std::cout << YELLOW << "$CLASS_NAME copy assignment operator called." << RST << std::endl;

	return *this;
}

$CLASS_NAME::~$CLASS_NAME()
{
	std::cout << RED << "$CLASS_NAME destructor called." << RST << std::endl;
}

/************ Member Functions ************/

	// Add member functions here

EOL

  echo "Class $CLASS_NAME created with .hpp and .cpp files."
}

# Loop to create classes
while true; do
  read -p "Enter the class name: " CLASS_NAME
  create_class "$CLASS_NAME"

  read -p "Do you want to add another class? (yes/no): " ADD_ANOTHER
  if [[ "$ADD_ANOTHER" != "yes" ]]; then
    echo "Exiting script."
    break
  fi
done
