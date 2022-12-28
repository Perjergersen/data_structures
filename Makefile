CC=gcc
flags=-Wall -Werror -Wextra
includes=./include/*.h
src=./src/*.c
test_src= ./test/test.c ./src/list.c
name=list

all: build run

rel: build-r run-r

build:
	$(CC) $(flags) $(includes) $(src) -o ./target/$(name)

run:
	./target/$(name)

build-r: 
	$(CC) $(flags) $(includes) $(src) -O3 -o ./target/$(name)_release

run-r:
	./target/$(name)_release

test-b:
	$(CC) $(flags) $(includes) $(test_src) -o ./target/$(name)_test

test-r:
	valgrind ./target/$(name)_test

clean:
	rm -rf ./target/$(name)
	rm -rf ./target/$(name)_release

format-all:
	clang-format -i $(includes) $(src) $(test_src)
