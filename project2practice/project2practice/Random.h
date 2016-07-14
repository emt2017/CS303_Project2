
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {

public:

	Random() {
		srand(std::time(0));
	}

	Random(int seed) {
		srand(seed);
	}

	int next_int(int n) {
		return int(random_rate() * n);
	}

	double random_rate() {
		double num= double(std::rand()) / RAND_MAX;
		return num;
	}

	bool Direction_Generator() {
		unsigned int direction;
		direction = rand() % 2;
		return direction;
	}

	unsigned int Current_Floor_Generator(unsigned int& num_floors) {
		unsigned int current_floor;
		current_floor = rand() % num_floors;

		return current_floor;
	}

	unsigned int Desired_Floor_Generator(unsigned int& num_floors, unsigned int& current_floor) {
		unsigned int desired_floor;
		bool equal = true;
		while (equal) {
			desired_floor = rand() % num_floors;
			if (desired_floor != current_floor) {
				equal = false;
			}
		}
		return desired_floor;
	}
};
