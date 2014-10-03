all: user-sorter

user-sorter: source.o userlist.o
	gcc source.o userlist.o -o user-sorter

source.o: source.c
	gcc -c source.c

userlist.o: userlist.c
	gcc -c userlist.c

clean:
	rm -rf *o user-sorter
