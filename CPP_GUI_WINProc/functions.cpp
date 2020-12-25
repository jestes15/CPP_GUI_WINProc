#include <random>

int randomInteger() {
	srand(46943);
	return rand() % 4000;
}