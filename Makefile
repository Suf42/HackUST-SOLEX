CPPFLAGS = -std=c++11

all: solex.exe

solex.exe: Block.o Blockchain.o Login.o Transaction.o Worldstate.o SHA256.o main.cpp
	g++ -o $@ $(CPPFLAGS) Block.o Blockchain.o Login.o Transaction.o Worldstate.o SHA256.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
