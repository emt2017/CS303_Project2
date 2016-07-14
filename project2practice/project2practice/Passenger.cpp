#include "Passenger.h"
//#include "Random.h"
//extern Random random;
//#include <ctime>

Passenger::Passenger(int arrive_time, unsigned int clock) {
	arrival_time = arrive_time;
	processing_time = Processing_Time_Generator(arrival_time, clock);
	id = id_num++;
}

int Passenger::id_num = 0;