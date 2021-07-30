//
//  Flight.h


#ifndef Flight_h
#define Flight_h

#include <string>
#include "Passenger.h"
#include <vector>
#include <string>

using namespace std;
class Flight
{
public:
    Flight();
    Flight(const string flightNumber, const int numOfRows, const int numOfSeatsPerRow, const int listSize);
    Flight(const Flight& source);
    Flight& operator= (const Flight& rhs);
    ~Flight();
    
    string get_flight_number() const;
    int get_rows() const;
    int get_seats_per_row() const;
    int get_size() const;
    
    void set_flight_number(const string& flight_num);
    void set_rows(const int& rows_num);
    void set_seats_per_row(const int& seats_per_r);
    void set_size(const int& list_size);
    void set_passenger_information(int index, string f_name, string l_name, string p_num, int s_num, char s_letter, int id);
    
    void populate_flight_from_file(string file_name);
    void display_passengers();
    void add_passenger();
    void remove_passenger();
    void display_map();
    void save_data(string file_name);
    
    void cleanStandardInputStream (void);
    string add_white_space(const string& source, const int& size);
    
private:
    string flight_number;
    int rows;
    int seats_per_row;
    int size;
    vector <Passenger> passengers;
};

#endif /* Flight_h */
