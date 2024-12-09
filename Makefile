NAME = getnextline.a
NAME_TEST = getnextline_test

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 7

SRC_TEST = get_next_line.c get_next_line_utils.c main.c 

test: $(NAME_TEST)

$(NAME_TEST): $(SRC_TEST)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC_TEST) -o $(NAME_TEST)

clean:
	rm -rf $(NAME) $(NAME_TEST)

retest: clean test
 
debug:
	cc -g get_next_line.c get_next_line_utils.c main.c

	
