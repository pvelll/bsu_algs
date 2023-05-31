#include <iostream>
using namespace std;
class Member {
public:
	int arrivalTime;
	int departureTime;
};

int main() {
	srand(time(NULL));
	int count;
	cout << "Input number of clients 1<= n <= 50; " << endl;
	cin >> count;
	if (count <= 1 || count >= 50) {
		while (count <= 1 || count >= 50) {
			cout << "Input again: " << endl;
			cin >> count;
		}
	}
	Member* members = new Member[count];
	for (size_t i = 0; i < count; i++)
	{
		cout << "enter the time of arrival and departure of " << i+1  << "st member " << endl;
		cout << "Time of arrival: ";
		cin >> members[i].arrivalTime;
		if (members[i].arrivalTime < 0 || members[i].arrivalTime > 24) {
			cout << "Input again: ";
			cin >> members[i].arrivalTime;
		}
		cout << "Time of departure: ";
		cin >> members[i].departureTime;
		if (members[i].departureTime < members[i].arrivalTime || members[i].departureTime > 24) {
			cout << "Input again: ";
			cin >> members[i].departureTime;
		}
	}
	int* membersAtTime = new int[24];
	int counter = 0;

	for (size_t time = 0; time < 24; time++)
	{
		for (size_t i = 0; i < count; i++)
		{
			if (members[i].arrivalTime == time)
				counter++;

			if (members[i].departureTime == time)
				counter--;
		}
		membersAtTime[time] = counter;
	}
	/*for (size_t time = 0; time <= 24; time++)
	{
		int counter = 0;
		for (size_t i = 0; i < count; i++)
		{
			if (members[i].arrivalTime <= time && members[i].departureTime >= time)
				counter++;
		}
		membersAtTime[time] = counter;
	}*/
	int max_num = membersAtTime[0];
	int max_index = 0;
	for (int i = 1; i < 24; i++) {
		if (membersAtTime[i] > max_num) {
			max_num = membersAtTime[i];
			max_index = i;
		}
	}

	cout << "Max num of members were at " << max_index << " Time " << " There were  " << max_num << " Members" << endl;

}