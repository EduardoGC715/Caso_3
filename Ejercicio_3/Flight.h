#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Flight {

private:
    tm flightTime;
    tm* aux;
    string airline;
    int flight_num;
    int passengers;

public:
    Flight(int pHour, int pMinutes, string pAirline, int pFlight_num, int pPassengers) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        aux=&flightTime;
        flightTime.tm_year= ltm->tm_year;
        flightTime.tm_mon= ltm->tm_mon;
        flightTime.tm_mday=ltm->tm_mday;
        flightTime.tm_isdst= ltm->tm_isdst;
        flightTime.tm_wday= ltm->tm_wday;
        flightTime.tm_yday= ltm->tm_yday;
        flightTime.tm_hour=pHour;
        flightTime.tm_min=pMinutes;
        flightTime.tm_sec=0;

        airline=pAirline;
        flight_num=pFlight_num;
        passengers=pPassengers;
    }
    string flightDetails(){
        string f_num = to_string(flight_num);
        string num_pass = to_string(passengers);
        string details = "Airline: "+airline+"\nFlight Number: "+f_num+"\nPassengers: "+num_pass+"\nFlight Date: "+flightTimeString()+"\n";
        return details;
    }
    char* flightTimeString() {
        char* result = asctime(aux);
        return result;
    }

    int getIntTimeValue() {
        int result = flightTime.tm_hour*100+flightTime.tm_min;
        return result;
    }
};
