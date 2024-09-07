CC=gcc
CC_LINUX=g++
ERROR_FLAGS=-Wall -Werror -Wextra
LDFLAGS=--std=c++17 -lstdc++ -lm
TEST_FLAGS=-g $(LDFLAGS)# -fsanitize=address
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
GTEST_FLAGS=-lgtest -lgtest_main
LINUX_FLAGS=-lpthread $(LIBS) -pthread -lrt -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TEST_SRC=$(wildcard ./s21_tests/s21_*.cc)
TEST_OBJ=$(patsubst ./s21_tests/s21_%.cc, %.o, $(TEST_SRC))

OS := $(shell uname -s)

ifeq ($(OS),Linux)
	OPEN_CMD=xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD=open
endif

all: clean test

test: clean
ifeq ($(OS),Darwin)
		$(CC) $(TEST_FLAGS) $(ERROR_FLAGS) $(GTEST_FLAGS) $(TEST_SRC) -o test $(LIBS)
else
		$(CC_LINUX) $(TEST_FLAGS) $(ERROR_FLAGS) $(TEST_SRC) $(GTEST_FLAGS) $(LINUX_FLAGS) -o test
endif
		clear
		./test

gcov_report: clean test
ifeq ($(OS), Darwin)
	$(CC) $(TEST_FLAGS) $(GCOV_FLAGS) $(GTEST_FLAGS) $(TEST_SRC) $(SRC) -o test $(LIBS)
else
	$(CC) $(TEST_FLAGS) $(GCOV_FLAGS) $(GTEST_FLAGS) $(TEST_SRC) $(SRC) -o test $(LINUX_FLAGS)
endif
	./test
	lcov -t "MatrixTests" -o s21_test.info -c -d . --ignore-errors mismatch --no-external
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

valgrind: clean test
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test


docker_alpine: clean
		cd docker_alpine && chmod +x run.sh && ./run.sh

docker_ubuntu: clean
		cd docker_ubuntu && chmod +x run.sh && ./run.sh

clang:
		clang-format --style=Google -n *.h s21_*/*.hpp s21_*/*.tpp s21_*/*.cc

to_clang:
		clang-format --style=Google -i *.h s21_*/*.hpp s21_*/*.tpp s21_*/*.cc

leaks:
		CK_FORK=no leaks --atExit -- ./test

brew:
		cd ~
		curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov:
ifeq ($(OS),Linux)
	sudo apt install lcov
endif
ifeq ($(OS),Darwin)
	brew install lcov
endif

clean_obj:
	rm -rf *.o

clean_lib:
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean: clean_lib clean_test clean_obj
	rm -rf *.dSYM
	rm -rf a.out
	rm -rf RESULT_VALGRIND.txt
	rm -rf *.gch

t:
	g++ tests.cc && ./a.out