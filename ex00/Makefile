# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontele <afontele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 15:28:07 by afontele          #+#    #+#              #
#    Updated: 2026/01/12 15:29:59 by afontele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Aprender como usar dependencias no Makefile

NAME = interface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRC = $(SRC_DIR)main.cpp $(SRC_DIR)Character.cpp $(SRC_DIR)Cure.cpp \
	$(SRC_DIR)Ice.cpp $(SRC_DIR)MateriaSource.cpp $(SRC_DIR)AMateria.cpp
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