CC:=gcc
CFLAGS=-Wall $(shell pkg-config --cflags check)
TST_LBS=$(shell pkg-config --libs check)
LIBRARY=s21_string.c main.c
TEST_LIBRARY=test.c s21_string.c token.c
NAME=main
TEST_NAME=./a.out
PATH2=../build/
BRANCH=develop_2
all:
	$(CC) $(CFLAGS) -o $(PATH2)$(NAME) $(LIBRARY)
clean:
	rm -f $(PATH2)$(NAME)
rebuild : clean all
test : test_del
	$(CC) $(CFLAGS) $(TST_LBS) -o $(TEST_NAME) $(TEST_LIBRARY) -lm
testing:
	$(CC) -g $(TEST_LIBRARY) -o $(TEST_NAME)   $(TST_LBS)
test_del :
	rm -f $(TEST_NAME) 
add:
	git add .
commit: 
	git commit -m "Stage commit"
push :
	git push origin $(BRANCH)
git : test_del add commit push
leak :
	valgrind $(TEST_NAME) --tool=memcheck
main :
	gcc main.c s21_string.c -o d -lm

_test:
	$(CC) -g $(TEST_LIBRARY) -o $(TEST_NAME)   $(TST_LBS) -lm --coverage
	./test
lcov : 
	lcov -t "Test_string" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
gcov : test _test lcov
