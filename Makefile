CXXFLAGS=-std=c++17 -g -static

9cpp: 9cpp.cpp

test: 9cpp
	./test.sh

clean:
	rm -f 9cpp *.o *~ tmp*

.PHONY: test clean