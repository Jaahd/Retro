CC =	/usr/bin/clang++
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir

NAME = ft_retro

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes

CFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(HPATH)
LFLAGS = -lncurses


SRC = main.cpp \
	  Environment.cpp \
	  PlayerShip.cpp \
	  Missile.cpp \
	  MissilePack.cpp \
	  EnemyPack.cpp \
	  Enemy.cpp \
	  Display.cpp \


OFILES = $(patsubst %.cpp, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Creating OBJ files"
	@echo "Building $@"
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
	@echo "\033[36mAll is done!\033[0m"

$(OPATH)/%.o: $(CPATH)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "Creating OBJ directory"
	@$(MKDIR) $@

clean:
	@echo "Deleting OBJ files"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[36mAll clear!\033[0m"

re: fclean all
