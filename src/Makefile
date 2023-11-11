CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
OBJ_DIR = objects/
SOURCE = $(wildcard *.c)
OBJECT = $(patsubst %.c, %.o, $(SOURCE))  # replace .c -> .o (making object files)
EXECUTABLE = test
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	GFLAGS = -lcheck_pic -lm -lsubunit
	RM_COMMAND = rm -rf test-parse.gcda test-parse.gcno test-floats.gcda test-floats.gcno test-itoa.gcda test-itoa.gcno test-test.gcda test-test.gcno
endif

ifeq ($(UNAME), Darwin)
	GFLAGS = -lcheck
	RM_COMMAND = rm test*.gcda test*.gcno parse*.gcda parse*.gcno floats*.gcda floats*.gcno itoa*.gcda itoa*.gcno
endif

all: clean string.a

string.a: clean $(OBJECT)
	# mkdir $(OBJ_DIR)
	ar rc string.a $(OBJECT)
	ranlib string.a
	rm -rf *.o

test: clean string.a
	$(CC) $(CFLAGS) test.c string.a -o $(EXECUTABLE) $(GFLAGS)
	./$(EXECUTABLE)

gcov_report: clean
	$(CC) $(CFLAGS) $(SOURCE) test.c -o $(EXECUTABLE) $(GFLAGS) --coverage
	./$(EXECUTABLE)
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html
	rm -rf *.gcno *.gcda *.gcov

style: clean
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c
	clang-format -n *.h
	rm -rf .clang-format

clang: clean
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c
	clang-format -i *.h
	rm -rf .clang-format

clean:
	rm -f *.o *.a *.gcno *.gcda *.info $(EXECUTABLE)
	rm -rf report $(OBJ_DIR)
