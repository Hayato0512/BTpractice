
CFLAGS = -g -Wall

hayato: main.o BT.o BTNode.o
	g++ -o hayato main.o BT.o BTNode.o -std=c++0x

main.o: main.cpp BTNode.h BT.h
	g++ -c main.cpp -std=c++0x $(CFLAGS)

BT.o : BT.cpp BT.h
	g++ -c BT.cpp -std=c++0x $(CFLAGS)

BTNode.o : BTNode.cpp BTNode.h
	g++ -c BTNode.cpp -std=c++0x $(CFLAGS)

clean:
	rm -f *.o hayato