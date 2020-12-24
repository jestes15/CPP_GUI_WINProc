#include <random>


int randInt() {
	srand(46943);
	return rand() % 4000;
}