/*
Student Name: EGE CAN KAYA
Student Number: 2018400018
Project Number: 3
Compile Status: SUCCESS
Running Status: SUCCESS
Notes: implemented lines A & B as just a single vector
*/
#include "SeatOperations.h"

using namespace std;

SeatOperations::SeatOperations(int N, int M){
    // create a vector of Person pointers of size N+M+1 (instead of N+M)
    // just for convenience, because this allows us to never use the 0th index.
    // initialize all of its values to 0.
    seats = *new vector<Person*>(N+M+1, 0);
    this->N = N;
    this->M = M;
}

// seat the current person and call the other function if needed
void SeatOperations::addNewPerson(int personType, const string& ticketInfo){
    // separate the line and the number
    string line = ticketInfo.substr(0,1);
    int parsedNo = stoi(ticketInfo.substr(1));
    // process the ticket number to find the appropriate position in the vector
    int processedNo = (line.find("A") != std::string::npos) ? (parsedNo % N) : ((parsedNo % M) + N);
    // there's no seat number 0, fix it if we get 0
    if (processedNo == N)
        processedNo = M + N;
    if (processedNo == 0)
        processedNo = N;
    // create a new person with the parsed information
    Person* p = new Person{ticketInfo, personType, parsedNo, processedNo};
    // targeted seat is empty
    if (!seats[processedNo]) {
        seats[processedNo] = p;
        p->currentSeat = processedNo;
    } else { // targeted seat is full. need to call the other function to deal with it
        Person* displaced = seats[processedNo];
        seats[processedNo] = p;
        p->currentSeat = processedNo;
        seatDisplacedPerson(displaced);
    }
}

// if someone is displaced during the seating, this function deals with it
void SeatOperations::seatDisplacedPerson(Person* displaced) {
    // check the type of person and perform the according operations
    if (displaced->type == 1) {
        // check if currently sitting at line A or B
        bool oldSeatIsA = (displaced->currentSeat <= N);
        int newSeat = oldSeatIsA ? ((displaced->parsedNo % M) + N) : (displaced->parsedNo % N);
        // there's no seat number 0, fix it if we get 0
        if (newSeat == N)
            newSeat = M + N;
        if (newSeat == 0)
            newSeat = N;

        // newSeat is not occupied
        if (!seats[newSeat]) {
            seats[newSeat] = displaced;
            displaced->currentSeat = newSeat;
        } else { // newSeat is occupied. need a recursive call.
            Person* newDisplaced = seats[newSeat];
            seats[newSeat] = displaced;
            displaced->currentSeat = newSeat;
            seatDisplacedPerson(newDisplaced);
        }

    } else if (displaced->type == 2) {
        int newSeat = ((displaced->currentSeat) + 1) % (M+N);
        // there's no seat number 0, fix it if we get 0
        if (newSeat == 0)
            newSeat = M+N;
        if (!seats[newSeat]) {
            seats[newSeat] = displaced;
            displaced->currentSeat = newSeat;
        } else { // targeted seat is occupied
            Person* newDisplaced = seats[newSeat];
            seats[newSeat] = displaced;
            displaced->currentSeat = newSeat;
            seatDisplacedPerson(newDisplaced);
        }
    } else { // is type 3
        int probe = displaced->type3Operation * displaced->type3Operation;
        // need to keep and operate with the initial processedNo, NOT currentSeat
        int newSeat = ((displaced->processedNo) + probe) % (M+N);
        // there's no seat number 0, fix it if we get 0
        if (newSeat == 0)
            newSeat = (M+N);
        if (!seats[newSeat]) {
            seats[newSeat] = displaced;
            displaced->currentSeat = newSeat;
            // increment for later operations
            displaced->type3Operation += 1;
        } else {
            Person* newDisplaced = seats[newSeat];
            seats[newSeat] = displaced;
            displaced->currentSeat = newSeat;
            displaced->type3Operation += 1;
            seatDisplacedPerson(newDisplaced);
        }
    }
}

void SeatOperations::printAllSeats(ofstream& outFile){
    for (int i = 1; i <= N+M; i++) {
        if (seats[i]) {
            outFile << seats[i]->type << " " << seats[i]->ticket << std::endl;
        } else {
            outFile << "0" << std::endl;
        }
    }
}