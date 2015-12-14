GCC = g++ 
FLAGS = -ansi -pedantic

run:a.out
	./a.out
a.out: *.o
	$(GCC)  *.o $(FLAGS)

*.o: *.cpp *.h
	$(GCC) -c -g *.cpp $(FLAGS)
	
clean:
	rm -f *.o a.out


