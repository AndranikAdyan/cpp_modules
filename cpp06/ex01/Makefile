NAME := a.out
CXX := c++ 
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

INC := Serializer.hpp
SRC := Serializer.cpp main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
