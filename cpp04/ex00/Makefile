NAME = animals

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
BUILD_DIR = ./.build
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: build $(NAME)

$(BUILD_DIR)/%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

build:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all build clean fclean re
