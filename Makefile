CC=g++

all: functions.o benchmark.o
	$(CC) functions.cpp benchmark.cpp -o benchmark -lpthread

benchmark.o: benchmark.cpp
	$(CC) -c benchmark.cpp -o benchmark.o

functions.o: functions.cpp functions.h
	$(CC) -c functions.cpp -o functions.o

clean:
	rm *.o benchmark