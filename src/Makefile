CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c11
TEST_FLAGS=-lcheck -lm -lpthread -lsubunit
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

SRC_DIR=.
TEST_DIR=../tests
BUILD_DIR=.
REPORT_DIR=report

SOURCES=$(shell find $(SRC_DIR) -name "*.c")
OBJECTS=$(SOURCES:.c=.o)
GCOV_OBJECTS=$(SOURCES:.c=.gcov.o)

TEST_SOURCES=$(shell find $(TEST_DIR) -name "*.c")
TEST_OBJECTS=$(TEST_SOURCES:.c=.o)

.PHONY: all rebuild clean test gcov_report

all: s21_string.a

s21_string.a: $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

%.gcov.o: %.c
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_OBJECTS) $(GCOV_OBJECTS)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_OBJECTS) $(GCOV_OBJECTS) $(TEST_FLAGS) -o test
	./test

gcov_report: test
	mkdir -p $(REPORT_DIR)
	lcov -t "s21_string_test" -o $(REPORT_DIR)/s21_string_test.info -c -d .
	genhtml -o $(REPORT_DIR) $(REPORT_DIR)/s21_string_test.info
	open $(REPORT_DIR)/index.html

clean:
	rm -rf *.o *.gcov.o
	rm -rf s21_string.a
	rm -rf test
	rm -rf *.gcda *.gcno
	rm -rf $(REPORT_DIR)
	rm -rf $(TEST_DIR)/*.o
	rm -rf $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno

rebuild: clean all