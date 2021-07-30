//
//  Passenger.h

#ifndef Passenger_h
#define Passenger_h
#include <string>
#include <stdio.h>
#include "Seat.h"
using namespace std;

class Passenger
{
public:
    Passenger();
    Passenger(const string firstName, const string lastName, const string phoneNumber, const int seatRow, const char seatNumber, const int idNumber);
    Passenger(const Passenger& source);
    Passenger& operator= (const Passenger& rhs);
    ~Passenger();
    
    string get_first_name() const;
    string get_last_name() const;
    string get_phone_number() const;
    int get_seat_number() const;
    char get_seat_letter() const;
    int get_id_number()const;
    
    void set_first_name(const string& firstName);
    void set_last_name(const string& lastName);
    void set_phone_number(const string& phoneNumber);
    void set_seat_number(const int& seatNum);
    void set_seat_letter(const char& seatLetter);
    void set_id_number(const int& idNumber);
    
private:
    string first_name;
    string last_name;
    string phone_number;
    Seat s;
    int id_number;
};
#endif /* Passenger_h */
