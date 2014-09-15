all: driver

driver: driver.o
	g++ -o driver tree.o driver.o

driver.o: driver.cpp tree.o
	g++ -c driver.cpp

tree.o: tree.cpp tree.h
	g++ -c tree.cpp 

clean:
	rm -rf *.o driver