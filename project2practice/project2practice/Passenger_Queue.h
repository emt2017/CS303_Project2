#include <string>
#include <queue>
#include "Passenger.h"
#include <iostream>
#include <ctime>
#include "Random.h"


using namespace std;

class Passenger_Queue {

public:

	Passenger_Queue(string my_name) :num_served(0), total_wait(0), queue_name(my_name) {}

	int get_total_wait() const {
		return total_wait;
	}

	string get_queue_name() const {
		return queue_name;
	}

	int get_num_served() {
		return num_served;
	}

	void set_arrival_rate(double new_arrival_rate) {
		arrival_rate = new_arrival_rate;
	}

	bool empty() const {
		return the_queue.empty();
	}

	size_t size() const {
		return the_queue.size();
	}

	void check_new_arrival(int clock, bool show_all);

	int update(int clock, bool show_all);



private:
	queue<Passenger> the_queue;

	int num_served;

	int total_wait;

	double arrival_rate;

	string queue_name;

	Random random;

};

void Passenger_Queue::check_new_arrival(int clock, bool show_all) {
	if (random.random_rate() < arrival_rate) { //arrival rate given through simulator
		Passenger newpass(clock);
		the_queue.push(newpass);
		if (show_all) {
			cout << "Time is "
				<< clock << ": "
				<< "Passenger " << newpass.get_id() << " arrived : new queue size is "
				<< the_queue.size() << endl;
		}
	}
}

int Passenger_Queue::update(int clock, bool show_all) {
	Passenger next_passenger = the_queue.front();
	the_queue.pop();
	int time_stamp = next_passenger.get_arrival_time();
	int wait = clock - time_stamp;
	total_wait += wait;
	num_served++;
	if (show_all) {
		cout << "Time is " << clock
			<< ": Serving "
			<< " with time stamp "
			<< time_stamp << endl;
	}
	return clock + next_passenger.get_processing_time();
}

