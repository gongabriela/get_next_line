NAME = getnextline.a
NAME_TEST = getnextline_test

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 1

SRC_TEST = get_next_line.c get_next_line_utils.c main.c

test: $(NAME_TEST)

$(NAME_TEST): $(SRC_TEST)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC_TEST) -o $(NAME_TEST)

clean:
	rm -rf $(NAME) $(NAME_TEST)

retest: clean test

debug:
	cc -g get_next_line.c get_next_line_utils.c main.c

buffertest: size1 size10 size100 size1000 size10000

size1: $(SRC_TEST)
	@echo "Compiling with BUFFER_SIZE=1"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRC_TEST) -o $(NAME_TEST)
#	./getnextline_test
	valgrind ./getnextline_test

size10: $(SRC_TEST)
	@echo "Compiling with BUFFER_SIZE=10"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=10 $(SRC_TEST) -o $(NAME_TEST)
#	./getnextline_test
	valgrind ./getnextline_test

size100: $(SRC_TEST)
	@echo "Compiling with BUFFER_SIZE=100"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=100 $(SRC_TEST) -o $(NAME_TEST)
#	./getnextline_test
	valgrind ./getnextline_test

size1000: $(SRC_TEST)
	@echo "Compiling with BUFFER_SIZE=1000"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1000 $(SRC_TEST) -o $(NAME_TEST)
#	./getnextline_test
	valgrind ./getnextline_test

size10000: $(SRC_TEST)
	@echo "Compiling with BUFFER_SIZE=10000"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=10000 $(SRC_TEST) -o $(NAME_TEST)
#	./getnextline_test
	valgrind ./getnextline_test
