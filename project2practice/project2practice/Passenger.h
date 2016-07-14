#include <iostream>
#include <set>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <list>
#include "Random.h"

using namespace std;

class Passenger {
public:

	Passenger(unsigned int arrival_time);

	unsigned int get_desired_floor() {
		return desired_floor;
	}

	unsigned int get_current_floor() {
		return current_floor;
	}

	unsigned int get_id() {
		return id;
	}

	bool get_direction() {
		return direction;
	}

	unsigned int get_processing_time() {
		return processing_time;
	}

	unsigned int get_arrival_time() {
		return arrival_time;
	}

	unsigned int Processing_Time_Generator(unsigned int& arrival_time, unsigned int& clock_cycles);

	unsigned int Id_Generator_Wrapper();
	
private:
	unsigned int desired_floor;//generator done

	unsigned int current_floor;//generator done

	unsigned int id;//generator done

	bool direction;//generator done

	unsigned int max_processing_time;

	unsigned int processing_time;//generator done

	unsigned int arrival_time;// generator done

	Random random;
};

void Spawn_Passenger(unsigned int& clock_cycles) {
}

/*unsigned int Spawn_Time_Generator(unsigned int& clock_cycles) {//iffy

	unsigned int wait_cycles;
	unsigned int spawn_time;

	srand(0);

	wait_cycles = rand() % 10;

	spawn_time = wait_cycles + clock_cycles;

	return spawn_time;

}*/

unsigned int Passenger::Processing_Time_Generator(unsigned int& arrival_time, unsigned int& clock_cycles) {
	return clock_cycles - arrival_time;
}

/*void Arrival_Time_Generator(unsigned int& clock_cycles) {
	unsigned int arrival_time;
	arrival_time = clock_cycles;
}*/

unsigned int Id_Generator(unsigned int& num_id) {
	unsigned int id;
	id = num_id++;
	return id;
}

unsigned int Passenger::Id_Generator_Wrapper() {
	unsigned int num_id = 0;
	Id_Generator(num_id);
}


