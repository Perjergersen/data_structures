CC=gcc
flags=
includes=./include/*.h
src=./src/*.c
all_C_and_H_files=./src/*.c ./include/*.h ./test/*.c ./test/*.h
name=data_structures
math=-lm

ilist_test_files=./src/ilist.c ./include/ilist.h ./test/ilist_test.c
ihashmap_test_files=./src/ihashmap.c ./include/ihashmap.h ./test/ihashmap_test.c

all: build run

init:
	mkdir include src target test

build: $(includes) $(src)
	@$(CC) $(flags) $(includes) $(src) -o ./target/$(name) $(math)

run: 
	@./target/$(name)

release: $(includes) $(src)
	@$(CC) $(flags) $(includes) $(src) -O3 -o ./target/$(name)_release $(math)
	@./target/$(name)_release

t: $(test_src)
	@$(CC) $(flags) $(includes) $(ilist_test_files) -o ./target/$(name)_ilist_test $(math)
	$(CC) $(flags) $(includes) $(ihashmap_test_files) -o ./target/$(name)_ihashmap_test $(math)
	@./target/$(name)_ilist_test
	@./target/$(name)_ihashmap_test

t-valgrind:
	@$(CC) $(flags) $(includes) $(ilist_test_files) -o ./target/$(name)_ilist_test $(math)
	@$(CC) $(flags) $(includes) $(ihashmap_test_files) -o ./target/$(name)_ihashmap_test $(math)
	@valgrind ./target/$(name)_ilist_test
	@valgrind ./target/$(name)_ihashmap_test

build-debug:
	@$(CC) $(flags) $(includes) $(src) -g -o ./target/$(name)_debug $(math)

clean:
	rm -rf ./target/*

format-all: $(includes) $(src)
	@clang-format -i $(all_C_and_H_files);
