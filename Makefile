
myspeller: myspeller.o mysearch.o
	g++ myspeller.o mysearch.o -o myspeller
myspeller.o: myspeller.cpp
	g++ -c myspeller.cpp
mysearch.o: mysearch.cpp mysearch.h
	g++ -c mysearch.cpp

clean:
	rm *.o myspeller

