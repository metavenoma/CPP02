NAME = Fixed
OBJ_PATH = objects/
INC = -I ./includes

SRC = sources/Fixed.cpp sources/main.cpp
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -g -std=gnu++11

$(OBJ_PATH)%.o : %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INC)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) $(INC) -o $(NAME)

all: $(NAME)

clean :
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm $(NAME)

re:fclean all

