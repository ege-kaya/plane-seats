#ifndef CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#define CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Person{
    int type= 0;
    int parsedNo= 0; // the ticket number initially read (has to be remembered for type 3)
    int processedNo = 0; // the position in the array
    int currentSeat = 0;
    int type3Operation= 1;
    string ticket;

    Person (string pTicket, int pType, int pParsedNo, int pProcessedNo) {
        ticket = pTicket;
        type = pType;
        parsedNo = pParsedNo;
        processedNo = pProcessedNo;
    }
};

class SeatOperations{

private:
    int N, M;
    std::vector<Person*> seats;
public:
    SeatOperations(int N, int M);
    void addNewPerson(int personType, const string& ticketInfo);
    void printAllSeats(ofstream& outFile);
    void seatDisplacedPerson(Person* displaced);
};

#endif //CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
