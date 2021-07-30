
//  Passenger.cpp
#include <stdio.h>
#include "Passenger.h"

Passenger::Passenger()
{
    first_name = '\0';
    last_name = '\0';
    phone_number = '\0';
    s.set_seat_number(0);
    s.set_seat_letter('\0');
    id_number = 0;
}

Passenger::Passenger(const string firstName, const string lastName, const string phoneNumber, const int seatRow, const char seatNumber, const int idNumber)
{
    first_name = firstName;
    last_name = lastName;
    phone_number = phoneNumber;
    s.set_seat_number(seatRow);
    s.set_seat_letter(seatNumber);
    id_number = idNumber;;
}

Passenger::Passenger(const Passenger& source)
{
    first_name = source.get_first_name();
    last_name = source.get_last_name();
    phone_number = source.get_phone_number();
    s.set_seat_number(source.get_seat_number());
    s.set_seat_letter(source.get_seat_letter());
    id_number = source.get_id_number();;
}

Passenger& Passenger::operator= (const Passenger& rhs)
{
    if(this != &rhs)
    {
        first_name = rhs.get_first_name();
        last_name = rhs.get_last_name();
        phone_number = rhs.get_phone_number();
        s.set_seat_number(rhs.get_seat_number());
        s.set_seat_letter(rhs.get_seat_letter());
        id_number = rhs.get_id_number();
        
    }
    return *this;
}

Passenger::~Passenger()
{
    first_name = '\0';
    last_name = '\0';
    phone_number = '\0';
    s.set_seat_number(0);
    s.set_seat_letter('\0');
    id_number = 0;
}

string Passenger::get_first_name() const
{
    return first_name;
}
string Passenger::get_last_name() const
{
    return last_name;
}
string Passenger::get_phone_number() const
{
    return phone_number;
}

int Passenger::get_seat_number() const
{
    return s.get_seat_number();
}
char Passenger::get_seat_letter() const
{
    return s.get_seat_letter();
}
int Passenger::get_id_number() const
{
    return id_number;
}

void Passenger::set_first_name(const string& firstName)
{
    first_name = firstName;
}
void Passenger::set_last_name(const string& lastName)
{
    last_name = lastName;
}
void Passenger::set_phone_number(const string& phoneNumber)
{
    phone_number = phoneNumber;
}
void Passenger::set_seat_number(const int& seatNum)
{
    s.set_seat_number(seatNum);
}
void Passenger::set_seat_letter(const char& seatLetter)
{
    s.set_seat_letter(seatLetter);
}
void Passenger::set_id_number(const int& idNumber)
{
    id_number = idNumber;
}
