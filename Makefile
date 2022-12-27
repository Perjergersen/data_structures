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

release: 
	$(CC) $(flags) $(includes) $(src) -O3 -o ./target/$(name)_release

run-release: release
	./target/$(name)_release

clean:
	rm -rf ./target/$(name)
	rm -rf ./target/$(name)_release

format-all:
	clang-format -i $(includes) $(src)
