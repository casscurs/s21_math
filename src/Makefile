NAME = arcf
HEADER = s21_math.h
SRCS = functions.c
OBJS	= $(patsubst %.c,%.o,$(SRCS))
D_FILES = $(patsubst %.c,%.d,$(SRCS))
FLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

%.o : %.c  $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(D_FILES)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re