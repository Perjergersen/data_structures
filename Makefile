CC=gcc
flags=-Wall -Werror -Wextra
includes=./include/*.h
src=./src/*.c
name=list

all: build run

build:
	$(CC) $(flags) $(includes) $(src) -o ./target/$(name)

run:
	./target/$(name)

clean:
	rm -rf ./target/$(name)

format-all:
	clang-format -i $(includes) $(src)
