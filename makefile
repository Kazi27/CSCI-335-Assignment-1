CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

PROG ?= main
OBJS = Card.cpp ActionCard.cpp PointCard.cpp Hand.cpp Player.cpp main.cpp

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(PROG) *.o

rebuild: clean all