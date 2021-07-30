//
//  Seat.cpp


#include <stdio.h>
#include "Seat.h"

Seat::Seat()
{
    seat_number = 0;
    seat_letter = 0;
}

Seat::Seat(const int seatNum, const char seatLetter)
{
    seat_number = seatNum;
    seat_letter = seatLetter;
}

Seat::Seat(const Seat& source)
{
    seat_number = source.get_seat_number();
    seat_letter = source.get_seat_letter();
}

Seat& Seat::operator= (const Seat& rhs)
{
    if(this != &rhs)
    {
        seat_number = rhs.get_seat_number();
        seat_letter = rhs.get_seat_letter();
    }
    return *this;
}

Seat::~Seat()
{
    seat_number = 0;
    seat_letter = '\0';
}

int Seat::get_seat_number() const
{
    return seat_number;
}

char Seat::get_seat_letter() const
{
    return seat_letter;
}

void Seat::set_seat_number(const int& sNum)
{
    seat_number = sNum;
}
void Seat::set_seat_letter(const char& sLetter)
{
    seat_letter = sLetter;
}
