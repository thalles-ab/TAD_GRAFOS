all:
	gcc -c src/*.c *.c
	gcc -o bin/main *.o
	make clean
clean:
	rm -f *.o *~ src/*.gch
run:
	./main