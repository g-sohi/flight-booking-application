//
//  Seat.h
//  finalProject

#ifndef Seat_h
#define Seat_h

class Seat
{
public:
    Seat();
    Seat(const int seatNum, const char seatLetter);
    Seat(const Seat& source);
    Seat& operator= (const Seat& rhs);
    ~Seat();
    
    int get_seat_number() const;
    char get_seat_letter() const;
    
    void set_seat_number(const int& sNum);
    void set_seat_letter(const char& sLetter);
    
private:
    int seat_number;
    char seat_letter;
};

#endif /* Seat_h */
