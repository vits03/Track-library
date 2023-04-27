CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic 

.PHONY : all


output:main.o hashtable.o track.o
	$(CXX) $(CXXFLAGS)	-o program  $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c  $^

hashtable.o: hashtable.cpp hashtable.h
	$(CXX) $(CXXFLAGS) -c  $^

track.o: track.cpp track.h
	$(CXX) $(CXXFLAGS) -c  $^
.PHONY : clean
clean:
	rm *.o program test