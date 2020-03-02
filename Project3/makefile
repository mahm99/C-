CXX = g++
CXXFLAGS = -Wall
CXXGDB = -g

proj3: Decay.o DecayList.o Node.o driver.cpp
	$(CXX) $(CXXFLAGS) Decay.o DecayList.o Node.o driver.cpp -o proj3

Decay.o: Decay.h Decay.cpp DecayList.o Node.o
	$(CXX) $(CXXFLAGS) -c Decay.cpp

DecayList.o: DecayList.h DecayList.cpp Node.o
	$(CXX) $(CXXFLAGS) -c DecayList.cpp

Node.o: Node.h Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

run:
	./proj3

val:
	valgrind ./proj3 

clean:
	rm *.o*
gdb:
	$(CXX) $(CXXGDB) Node.h Node.cpp DecayList.h DecayList.cpp driver.cpp Decay.h Decay.cpp
	gdb a.out
