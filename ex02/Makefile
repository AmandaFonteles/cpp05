# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontele <afontele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 15:28:07 by afontele          #+#    #+#              #
#    Updated: 2026/02/02 14:48:34 by afontele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form1

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRC = $(SRC_DIR)main.cpp $(SRC_DIR)AForm.cpp $(SRC_DIR)Bureaucrat.cpp \
	  $(SRC_DIR)PresidentialPardonForm.cpp $(SRC_DIR)RobotomyRequestForm.cpp \
	  $(SRC_DIR)ShrubberyCreationForm.cpp
INC = -I inc
OBJDIR = obj/
SRC_DIR = src/
OBJ = $(patsubst $(SRC_DIR)%.cpp,$(OBJDIR)%.o,$(SRC))

$(OBJDIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(NAME) $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re