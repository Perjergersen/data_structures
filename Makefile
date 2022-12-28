CC=gcc
flags=-Wall -Werror -Wextra
includes=./include/*.h
src=./src/*.c
test_src= ./test/test.c ./src/list.c
name=list
math=-lm

all: build run

init:
	mkdir include src target test

build: $(includes) $(src)
	$(CC) $(flags) $(includes) $(src) -o ./target/$(name) $(math)

run: 
	./target/$(name)

release: $(includes) $(src)
	$(CC) $(flags) $(includes) $(src) -O3 -o ./target/$(name)_release $(math)
	./target/$(name)_release

t: $(test_src)
	$(CC) $(flags) $(includes) $(test_src) -o ./target/$(name)_test $(math)
	valgrind ./target/$(name)_test

clean:
	rm -rf ./target/$(name)
	rm -rf ./target/$(name)_release
	rm -rf ./target/$(name)_test

format-all: $(includes) $(src)
	clang-format -i $(includes) $(src) $(test_src)
