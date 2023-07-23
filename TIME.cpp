#include <iostream>
#include <ctime>

using namespace std;

class digitalclock 
{
    private:
        int hours;
        int minutes;

    public:
        void getCurrentTime() 
        {
            time_t now = time(0);
            tm* currentTime = localtime(&now);

            hours = (currentTime->tm_hour + 5) % 24;
            minutes = currentTime->tm_min + 30;

            if (minutes >= 60) 
            {
                minutes %= 60;
                hours = (hours + 1) % 24;
            }
        }
        void displayTime()
        {
            cout << "Current Time: ";
            if (hours < 10) 
            {
            cout << "0" << hours << ":";
            } 
            else 
            {
                cout << hours << ":";
            }

            if (minutes < 10) 
            {
                cout << "0" << minutes;
            } 
            else 
            {
                cout << minutes;
            }
            cout << endl;

            int timeRemaining = (24 - hours) * 60 * 60 - minutes * 60;
            int hoursLeft = timeRemaining / 3600;
            int minutesLeft = (timeRemaining % 3600) / 60;

            cout << "\nTime Left to Start a New Day: ";
            cout << hoursLeft << " hours, " << minutesLeft << " minutes " << endl;
        }
};

int main() 
{
    
    digitalclock time_clock;
    time_clock.getCurrentTime();
    time_clock.displayTime();

    return 0;
}

