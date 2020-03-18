INC_DIR		= include/

CC	= gcc
CFLAGS	+= -I $(INC_DIR)
CFLAGS	+= -g3 -Wall -Wextra -Werror
CFLAGS	+= -fPIC

RM	= rm -f

NAME	= libmy_malloc.so

SRCS_DIR	= src/
SRCS_FILES	=	malloc.c \
				free.c \
				calloc.c \
				realloc.c

SRCS	= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)

UNIT_TEST = --coverage -lcriterion
SRC_TEST = 	tests/tests.c \
			tests/malloc.c

OBJ_TEST = $(SRC_TEST:.c=.o)
NAME_TEST = unit_tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lm -fPIC -shared
clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_TEST)
	$(RM) *.gcno
	$(RM) *.gcda

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)
	$(RM) vgcore*

re:	fclean all

tests_run : $(OBJ) $(OBJ_TEST)
		gcc -o $(NAME_TEST) $(SRCS) $(OBJ_TEST) $(UNIT_TEST) $(LDFLAGS) $(CFLAGS) -lm -ldl
		./unit_tests
		gcovr --exclude tests/

.PHONY: all clean fclean re tests_run