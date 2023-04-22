#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// function to return AM/PM respect to hour of time

string GetAM_PM(int twelve_hours) {
	return twelve_hours >= 12 ? " PM " : " AM ";
}

// converting it into 12 hour format

int TwelveHourFormat(int twelve_hours) {
	return (twelve_hours == 0 || twelve_hours == 12) ? 12 :
		twelve_hours % 12;
}

// printing the 12 hour format
void Display_12_HourFormat(int second, int minutes, int twelve_hours) {

	cout.fill('0');
	cout << TwelveHourFormat(twelve_hours) << ":" << minutes << ":" << seconds << " " << GetAM_PM(twelve_hours);
}

// printing the 24 hour format

void Display_24_HourFormat(int seconds, int minutes, int twenty_four_hours) {
	cout.fill('0');
	cout << twenty_four_hours << ":" << minutes << ":" << seconds;
}

void AddHour(int hour) {
	hour = (hour + 1) % 24;

}

void AddMinute(int hour, int min) {
	if (min == 59) {
		AddHour(hour);

    }
	min = (min + 1) % 60;
}

void AddSecond(int min, int sec) {
	if (sec == 59) {
		AddMinute(min, sec);

	}
	sec = (sec + 1) % 60;

}

// This method prints the menu options
void DisplayMenu() {
	cout << "Chada Tech Clocks Menu" << endl;
	cout << "[1] Add one hour" << endl;
	cout << "[2] Add one minute" << endl;
	cout << "[3] Add one second" << endl;
	cout << "[4] Exit program" << endl;

}

int main()
{
	int second, minutes, hours;

	// obtains current time in seconds

	time_t total_seconds = time(0);

	// getting values of seconds, minutes
	struct tm ct;
	localtime_s(&ct, &total_seconds);

	seconds = ct.tm_sec;
	minutes = ct.tm_min;
	hours = ct.tm_hour;

	// variable declared
	int option;
	do
	{
		// DisplayMenu function is called
		DisplayMenu();

		cin >> option;
		// If user input is 1, Clock function is called
		if (option == 1) {

			TwelveHourFormat(hours);
			AddHour(hours);
			GetAM_PM(hours);
			Display_12_HourFormat(seconds, minutes, hours);
			Display_24_HourFormat(seconds, minutes, hours);

		}

		// If the option is 2, the Clock function is called
		else if (option == 2) {
			AddMinute(minutes, seconds);
			GetAM_PM(hours);

		}

		//If option is 3, the Clock function is called
		else if (option == 3) {
			AddSecond(minutes, seconds);
			GetAM_PM(hours);

		}

		// if the option is 4, exit message prints and application stops running
		else if (option == 4) {
			cout << " You have exited the application.";
			break

		}
		else {
			cout << "You have entered an invalid input." << endl;

		}
	} while (option != 4);

}



	
   


