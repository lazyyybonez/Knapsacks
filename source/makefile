make: main

main: knapsacks.o main.o
	g++ -o main main.cpp knapsacks.cpp

knapsacks.o: knapsacks.cpp knapsacks.h
	g++ -c -std=c++11 knapsacks.cpp knapsacks.h

main.o: main.cpp knapsacks.h
	g++ -c -std=c++11 main.cpp knapsacks.h

clean:
	rm *.o main
