crypxor.o: crypxor.c
	gcc -c crypxor.c

.PHONY: all clean install uninstall
all:
	gcc -c crypxor.c
clean:
	rm -rf *.o
install: crypxor.o
	gcc -o crypxor crypxor.o
	mv crypxor /usr/bin/crypxor
uninstall: /usr/bin/crypxor
	rm -f /usr/bin/crypxor