all: driver

driver: driver.o
	g++ tree.o node.o driver.o -o driver

node.o: node.cpp node.h
	g++ -c node.cpp 

tree.o: tree.cpp tree.h
	g++ -c tree.cpp 

driver.o: tree.o node.o
	g++ -c driver.cpp

clean:
	rm -rf *.o driver