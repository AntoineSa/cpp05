# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 10:50:04 by asablayr          #+#    #+#              #
#    Updated: 2021/02/21 10:36:43 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureau

INCS =	Bureaucrat.hpp 

SRCS =	main.cpp \
		Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++
C_FLAGS = -Wall -Werror -Wextra -std=c++98

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
