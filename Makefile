
plapuzzle:  plapuzzle.cpp
	gcc -O3 -Wall -o $@ plapuzzle.cpp


run: plapuzzle
	./plapuzzle
