CC = g++

FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17
LINK_LIBRARIES = -lgtest

SRC_C_FILES = lib/*.cc
TEST_C_FILES = tests/*.cc

TEST_TARGET = s21_test

LIB = s21_matrix_oop.a

.PHONY: all test $(LIB)

all: clean test $(LIB)

clang:
	clang-format -style="{BasedOnStyle: Google}" -i $(wildcard */*.cc *.cc */*.h *.h)

test: clang $(SRC_C_FILES) $(SRC_H_FILES)
	$(CC) $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(LINK_LIBRARIES)
	./$(TEST_TARGET)

$(LIB): clang
	$(CC) -c $(SRC_C_FILES) $(LINK_LIBRARIES)
	ar rcv $(LIB) *.o
	ranlib $(LIB)
	rm *.o

gcov_report: clang
	$(CC) --coverage $(FLAGS) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(LINK_LIBRARIES)
	./$(TEST_TARGET)
	lcov -t "$(TEST_TARGET)" -o $(TEST_TARGET).info -c -d .
	genhtml -o report $(TEST_TARGET).info
	rm *.gcda *.gcno *.info

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean:
	rm -f $(TEST_TARGET)
	rm -f $(LIB)
	rm -f *.o