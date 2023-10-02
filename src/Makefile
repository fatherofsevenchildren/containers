# GCC=gcc
# SRC=s21_matrix_oop.cc
# OBJ=s21_matrix_oop.o
# CFLAGS=--std=c++17 -lstdc++ -lm
# TESTFLAGS=-lgtest -lgcov
# GCOVFLAGS=--coverage
# HTML=lcov -t "report" -c -d .
CC=gcc
CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
TEST_FLAGS:=$(CFLAGS) -g #-fsanitize=address -O1 -fno-omit-frame-pointer
LINUX_FLAGS =-lrt -lpthread -lm -lsubunit
GCOV_FLAGS?=--coverage#-fprofile-arcs -ftest-coverage
LIBS=-lgtest
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose
HEADER=s21_containers.h
TEST_SRC=test.cc


all: clean gcov

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM *.out

test: 
	g++ test.cc -lgtest -pthread && ./a.out


gcov_report: clean
	$(CC) $(TEST_FLAGS) $(GCOV_FLAGS) $(LIBS) $(CPPFLAGS) $(TEST_SRC) -o gcov_report 
	./gcov_report
	lcov -t "stest" -o s21_test.info -c -d ./ --no-external --ignore-errors mismatch
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

clang: 
	clang-format -style=Google -i *.cc *.h


.PHONY: test, gcov
