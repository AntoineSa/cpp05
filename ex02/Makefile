# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 10:50:04 by asablayr          #+#    #+#              #
#    Updated: 2021/03/04 14:42:09 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureau

INCS =	Bureaucrat.hpp \
		ShrubberyCreation.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \
		Form.hpp 

SRCS =	main.cpp \
		Bureaucrat.cpp \
		ShrubberyCreation.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Form.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
C_FLAGS_O = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(C_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: 	fclean
	make all
