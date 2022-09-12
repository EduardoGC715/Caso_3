#include <cstdlib>
#include "Flight.h"
#include "List.h"
#include "Priority_Queue.h"



List<Flight>* fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    auto* flights_list = new List<Flight>();
    string airlines [10]={"Qatar Airways","Singapore Airlines","ANA All Nippon Airways","Emirates","Japan Airlines","Cathay Pacific Airways","EVA Air","Qantas Airways","Hainan Airlines","Air France"};
    srand (time(nullptr));
    for(int i=0; i<pCantidad; i++){
        int hour=rand()%(pEndHour-pStartHour)+pStartHour;
        int delay=rand()%17;
        int minute=rand()%(60-delay);
        string airline =airlines[rand()%10];
        int flight_num=rand()%50;
        int passengers=rand()%200+1;
        auto *nflight = new Flight(hour,minute,airline,flight_num,passengers);
        flights_list->add(nflight);
    }
    return flights_list;
}

List<Queue<Flight>>* setupRunways(int pRunways){
    auto* listRunways = new List<Queue<Flight>>();
    for(int i=0;i<pRunways;i++){
        auto* runway = new Queue<Flight>();
        listRunways->add(runway);
    }
    return listRunways;
}

List<Queue<Flight>>* scheduleFlights(int pQuantity, int pStartHour, int pEndHour, int pRunways){
    auto* flights = new List<Flight>();
    auto* runways = new List<Queue<Flight>>();
    flights=fillFlights(pQuantity, pStartHour, pEndHour);
    runways= setupRunways(pRunways);
    int aux=0;
    while(!flights->isEmpty()){
        if(aux==pRunways){
            aux=0;
        }
        runways->find(aux)->enqueue(flights->getFirst()->getData(),flights->getFirst()->getData()->getIntTimeValue());
        flights->remove(0);
        aux++;
    }
    return runways;
}

void launchFlights(List<Queue<Flight>>* pAirport, int pStartHour, int pEndHour){
    for(int current_time=pStartHour*100;current_time<pEndHour*100;current_time++){
        cout<<"tiempo actual: "<<current_time<<endl;
        for(int runway=0;runway<pAirport->getSize();runway++) {
            if (pAirport->find(runway)->front()!=NULL){
                if (pAirport->find(runway)->front()->getIntTimeValue() <= current_time) {
                    cout<<"\nDespego de la pista "<<runway<<" el avion:\n"<<pAirport->find(runway)->dequeue()->flightDetails();
                }
            }
        }
    }
}

int main() {
    auto* airport = new List<Queue<Flight>>();
    airport=scheduleFlights(10,1,2,5);
    launchFlights(airport,1,2);
}