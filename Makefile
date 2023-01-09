CC=gcc
flags=-Wall -Werror -Wextra
includes=./include/*.h
src=./src/*.c
all_C_and_H_files=./src/*.c ./include/*.h ./test/*.c ./test/*.h
name=data_structures
math=-lm

ilist_test_files=./src/ilist.c ./include/ilist.h ./test/ilist_test.c
ihashmap_test_files=./src/ihashmap.c ./include/ihashmap.h ./test/ihashmap_test.c

all: ./target/$(name) run

init:
	mkdir target target/dslib

./target/$(name): $(includes) $(src)
	@$(CC) $(flags) $(includes) $(src) -o $@ $(math)

run: 
	@./target/$(name)

release: $(includes) $(src)
	@$(CC) $(flags) $(includes) $(src) -O3 -o ./target/$(name)_release $(math)
	@./target/$(name)_release

t: $(test_src)
	@$(CC) $(flags) $(includes) $(ilist_test_files) -o ./target/$(name)_ilist_test $(math)
	@$(CC) $(flags) $(includes) $(ihashmap_test_files) -o ./target/$(name)_ihashmap_test $(math)
	@./target/$(name)_ilist_test
	@./target/$(name)_ihashmap_test

t-valgrind:
	@$(CC) $(flags) $(includes) $(ilist_test_files) -o ./target/$(name)_ilist_test $(math)
	@$(CC) $(flags) $(includes) $(ihashmap_test_files) -o ./target/$(name)_ihashmap_test $(math)
	@valgrind ./target/$(name)_ilist_test
	@valgrind ./target/$(name)_ihashmap_test

build-debug:
	@$(CC) $(flags) $(includes) $(src) -g -o ./target/$(name)_debug $(math)

./target/dslib/libihashmap.so: src/ihashmap.c include/ihashmap.h
	$(CC) $(flags) -fPIC -shared -o $@ src/ihashmap.c -lc

./target/dslib/libilist.so: src/ilist.c include/ilist.h
	$(CC) $(flags) -fPIC -shared -o $@ src/ilist.c -lc

./target/dslib/libivector.so: src/ivector.c include/ivector.h
	$(CC) $(flags) -fPIC -shared -o $@ src/ivector.c -lc

./target/dslib/libiqueue.so: src/iqueue.c include/iqueue.h
	$(CC) $(flags) -fPIC -shared -o $@ src/iqueue.c -lc

./target/dslib/libistack.so: src/istack.c include/istack.h
	$(CC) $(flags) -fPIC -shared -o $@ src/istack.c -lc

./target/dslib/libsafe_xallocs.so: src/safe_xallocs.c include/safe_xallocs.h
	$(CC) $(flags) -fPIC -shared -o $@ src/safe_xallocs.c -lc

gen-libs: ./target/dslib/libsafe_xallocs.so ./target/dslib/libistack.so ./target/dslib/libiqueue.so ./target/dslib/libivector.so ./target/dslib/libilist.so ./target/dslib/libihashmap.so

clean:
	rm -rf ./target/*

install: init gen-libs
	mkdir /usr/include/dslib
	cp ./include/* /usr/include/dslib
	cp ./target/dslib/* /usr/lib/

format-all: $(includes) $(src)
	@clang-format -i $(all_C_and_H_files);
