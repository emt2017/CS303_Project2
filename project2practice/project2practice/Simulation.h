#include "Passenger_Queue.h"

class Simulation {

public:

	Simulation() : queue("Standard"), clock(0), time_done(0) {}

	Simulation(double frequent_arrival_rate, double regular_arrival_rate, int frequent_flyer_max, int total_time, bool show_all) :
		queue("Standard"), total_time(total_time), show_all(show_all) {

		queue.set_arrival_rate(regular_arrival_rate);
	}

	void run_simulation();

	void show_stats();

	//void enter_data();


private:

	void start_serve();

	Passenger_Queue queue;

	int total_time;

	bool show_all;

	int clock;

	int time_done;

};

void Simulation::run_simulation() {
	for (clock = 0; clock < total_time; clock++) {
		queue.check_new_arrival(clock, show_all);
	/*	if (elevator stop) {
			clock++;
		}*/
		if (clock >= time_done) {
			start_serve();
		}
	}
}

void Simulation::start_serve() {
	if (!queue.empty()) {
		// Serve the next passenger.
		time_done = queue.update(clock, show_all);
	}
	else if (show_all) {
		cout << "Time is " << clock
			<< ": Server is idle\n";
	}
}


void Simulation::show_stats() {
	cout << "\n The number of passengers served was "
		<< queue.get_num_served() << endl;
	double average_waiting_time = double(queue.get_total_wait())
		/ double(queue.get_num_served());

	cout << " with an average waiting time of "
		<< average_waiting_time << endl;

	cout << "Passengers in regular passenger queue:"
		<< queue.size() << endl;
}

