//  Flight.cpp

#include <stdio.h>
#include <string>
#include "Flight.h"
#include "Passenger.h"
#include <fstream>
#include <iostream>
#include <vector>

Flight::Flight()
{
    flight_number = '\0';
    rows = 0;
    seats_per_row = 0;
    size = 0;
}

Flight::Flight(const string flightNumber, const int numOfRows, const int numOfSeatsPerRow, const int listSize)
{
    flight_number = flightNumber;
    rows = numOfRows;
    seats_per_row = numOfSeatsPerRow;
    size = listSize;
}
Flight::Flight(const Flight& source)
{
    flight_number = source.get_flight_number();
    rows = source.get_rows();
    seats_per_row = source.get_seats_per_row();
    size = source.get_size();
}

Flight& Flight::operator= (const Flight& rhs)
{
    if(this != &rhs)
    {
        flight_number = rhs.get_flight_number();
        rows = rhs.get_rows();
        seats_per_row = rhs.get_seats_per_row();
        size = rhs.get_size();
    }
    return *this;
}

Flight::~Flight()
{
    flight_number = '\0';
    rows = 0;
    seats_per_row = 0;
    size = 0;
}

string Flight::get_flight_number() const
{
    return flight_number;
}

int Flight::get_rows() const
{
    return rows;
}

int Flight::get_seats_per_row() const
{
    return seats_per_row;
}

int Flight::get_size() const
{
    return size;
}
               
void Flight::set_flight_number(const string& flight_num)
{
    flight_number = flight_num;
}

void Flight:: set_rows(const int& rows_num)
{
    rows = rows_num;
}

void Flight::set_seats_per_row(const int& seats_per_r)
{
    seats_per_row = seats_per_r;
}

void Flight::set_size(const int& list_size)
{
    size = list_size;
}

void Flight::set_passenger_information(int index, string f_name, string l_name, string p_num, int s_num, char s_letter, int id)
{
    passengers[index].set_first_name(f_name);
    passengers[index].set_last_name(l_name);
    passengers[index].set_phone_number(p_num);
    passengers[index].set_seat_number(s_num);
    passengers[index].set_seat_letter(s_letter);
    passengers[index].set_id_number(id);
}

void Flight::populate_flight_from_file(string file_name)
{
    ifstream in_stream;
    in_stream.open(file_name);
    
    if(in_stream.fail())
    {
        cout <<"Error opening file..." <<endl;
        exit(1);
    }
       
    in_stream >> flight_number >> rows >> seats_per_row;
    
    string white_space;
    getline(in_stream, white_space);
    
    string line;
    int i = 0;
       
    while(in_stream.good())
    {
        string fName;
        string lName;
        string pNum;
        int sRow;
        char sLetter;
        int id;
    
        getline(in_stream, line);
    
        if(line.length() > 0)
        {
            fName = line.substr(0, 20);
            lName = line.substr(20, 20);
            pNum = line.substr(40, 20);
            sRow = stoi(line.substr(60, 1));
            sLetter = line.substr(61, 1)[0];
            if(isdigit(sLetter))
            {
                sRow = stoi(line.substr(60, 2));
                sLetter = line.substr(62, 1)[0];
            }
            id = stoi(line.substr(64,5));
        }
        
    if(fName[0] < 65)
        break;
        
    size++;
    passengers.resize(size);
    set_passenger_information(i, fName, lName, pNum, sRow, sLetter, id);
    i++;
    }
    
    in_stream.close();
}

void Flight::display_passengers()
{
    cout << "First Name\t" << "   Last Name\t\t" << "Phone Number\t" << "   Row\t\t" << "Seat\t\t" << "ID\t" << endl;
    for(int i = 0; i < 95; i++)
    {
        cout << "-";
    }
    cout << endl;
    for(int j = 0; j < passengers.size(); j++)
    {
        cout << passengers[j].get_first_name();
        cout << passengers[j].get_last_name();
        cout << passengers[j].get_phone_number()<<" ";
        cout << passengers[j].get_seat_number() << "\t\t ";
        cout << passengers[j].get_seat_letter() << "\t\t";
        cout << passengers[j].get_id_number() << endl;
        
        for(int i = 0; i < 95; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
}

void Flight::add_passenger()
{
    string p_first_name;
    string p_last_name;
    string p_phone_number;
    int p_seat_row;
    char p_seat_letter;
    int p_id_number;
    
    int check = 1;
    
    cout << "Please enter the passenger's ID: ";
    cin >> p_id_number;
    while(cin.fail())
    {
        cout << "Invalid input. Enter a 5 digit ID Number.\n";
        cin.clear();
        cleanStandardInputStream();
        cin >> p_id_number;
    }

    for(int i = 0; i < passengers.size(); i++)
    {
        if(passengers[i].get_id_number() == p_id_number || passengers[0].get_id_number() == p_id_number)
        {
            cout << "This passenger already exists." << endl;
            check = 0;
            break;
        }
    }
    
    if(check != 0)
    {
        size++;
        passengers.resize(size);
    
        //enter first name
        cout << "Please enter the passenger's first name: ";
        cin >> p_first_name;
        while(cin.fail())
        {
            cout << "Invalid input. Enter a string with a maximum of 20 characters.\n";
            cin.clear();
            cleanStandardInputStream();
            cin >> p_first_name;
        }
        p_first_name = add_white_space(p_first_name, 20);
        //enter last name
        cout << "Please enter the passenger's last name: ";
        cin >> p_last_name;
        while(cin.fail())
        {
            cout << "Invalid input. Enter a string with a maximum of 20 characters.\n";
            cin.clear();
            cleanStandardInputStream();
            cin >> p_last_name;
        }
        p_last_name = add_white_space(p_last_name, 20);
        //enter phone number
        cout << "Please enter the passenger's phone number: ";
        cin >> p_phone_number;
        while(cin.fail())
        {
            cout << "Invalid input. Enter a string with a maximum of 20 characters.\n";
            cin.clear();
            cleanStandardInputStream();
            cin >> p_phone_number;
        }
        
        //check if the phone number format is not "xxx-xxx-xxxx"
        if(p_phone_number.length() == 10 || (p_phone_number[3] == ' ' && p_phone_number[7] == ' '))
        {
            p_phone_number.insert(3, "-");
            p_phone_number.insert(7, "-");
        }
        p_phone_number = add_white_space(p_phone_number, 20);
        
        //enter seat row
        cout << "Please enter the passenger's desired row: ";
        cin >> p_seat_row;
        while(cin.fail())
        {
            cout << "Invalid input. Enter a seat row consisting of 1 number.\n";
            cin.clear();
            cleanStandardInputStream();
            cin >> p_seat_row;
        }
        
        //enter seat letter
        cout << "Please enter the passenger's desired seat: ";
        cin >> p_seat_letter;
        while(cin.fail())
        {
            cout << "Invalid input. Enter a seat consisting of 1 character.\n";
            cin.clear();
            cleanStandardInputStream();
            cin >> p_seat_letter;
        }
        
        //check if seat is taken
        for(int i = 0; i < passengers.size(); i++)
        {
            //check if seat row & number is equal to the passenger at the current index or the first passenger
            if(((passengers[i].get_seat_number() == p_seat_row) && (passengers[i].get_seat_letter() == p_seat_letter)) || ((passengers[0].get_seat_number() == p_seat_row) && (passengers[0].get_seat_letter() == p_seat_letter)))
            {
                cout << "This seat is taken. Please enter another seat row: ";
                cin >> p_seat_row;
                while(cin.fail())
                {
                    cout << "Invalid input. Enter a seat row consisting of 1 number.\n";
                    cin.clear();
                    cleanStandardInputStream();
                    cin >> p_seat_row;
                }

                cout << "Please enter another seat: ";
                cin >> p_seat_letter;
                while(cin.fail())
                {
                    cout << "Invalid input. Enter a seat consisting of 1 character.\n";
                    cin.clear();
                    cleanStandardInputStream();
                    cin >> p_seat_letter;
                }
                //reset index
                i = 0;
            }
        }
        set_passenger_information(size-1, p_first_name, p_last_name, p_phone_number, p_seat_row, p_seat_letter, p_id_number);
        cout << "Passenger succesfully added." << endl;
    }
}

void Flight::remove_passenger()
{
    int p_id_number;
    int check = 0;
    
    cout << "Please enter the passenger's ID: ";
    cin >> p_id_number;
    while(cin.fail())
    {
        cout << "Invalid input. Enter a 5 digit ID Number.\n";
        cin.clear();
        cleanStandardInputStream();
        cin >> p_id_number;
    }
        
    for(int i = 0; i < passengers.size(); i++)
    {
        if(p_id_number == passengers[i].get_id_number())
        {
            passengers.erase(passengers.begin()+i);
            cout << "Passenger deleted." << endl;
            check = 1;
            break;
        }
    }
    
    if(check == 0)
    {
        cout << "Passenger was not found." << endl;
    }
}

void Flight::display_map()
{
    char col = 'A';
    int seat_row [passengers.size()];
    char seat_letter[passengers.size()];
    int seat_row_taken = 0;
    int seat_letter_taken = 0;
    

    for(int i = 0; i < passengers.size(); i++)
    {
        seat_row[i] = passengers[i].get_seat_number();
        seat_letter[i] = passengers[i].get_seat_letter();
    }
    
    cout << "\t";
    
    //Display Columns
    for(int i = 0; i < seats_per_row; i++)
    {
        cout << col << "\t";
        col++;
    }
    cout << endl;
    
    //Display seats : Outermost loop is for each row
    for(int i = 1; i < rows; i++)
    {
        //Add dividers between each row
        cout << "\t";
        for(int j = 0; j < seats_per_row; j++)
        {
            cout << "----+---";
        }
        cout << endl;
        
        //Display each row number and seats taken
        cout << "   " << i << "\t";
        
        //This loop is for each column
        for(int j = 0; j < seats_per_row; j++)
        {
            //This loop is to traverse through arrays to find matching row and letter
            for(int k = 0; k < passengers.size(); k++)
            {
                if(seat_row[k] == i)
                {
                    seat_row_taken = 1;
                }
                
                if((seat_letter[k] - 'A') == j)
                {
                    seat_letter_taken = 1;
                }
                
                if(seat_row_taken == 1 && seat_letter_taken == 1)
                {
                    cout << "X";
                }
                
                seat_row_taken = 0;
                seat_letter_taken = 0;
            }
            cout << "\t";
        }
        cout << endl;
    }
}

void Flight::save_data(string file_name)
{
    char option;
    cout << "Would you like to save the data into 'flight_info.txt'. Please enter 'Y' or 'N'" << endl;
    cin >> option;
    
    if(option == 'Y' || option == 'y')
    {
        ofstream out_stream;
        out_stream.open(file_name);
        
        if(out_stream.fail())
        {
            cout << "Error. File could not be opened..." << endl;
            exit(1);
        }
        
        out_stream << flight_number << "\t" << rows << "\t" << seats_per_row << endl;
        
        for(int i = 0; i < passengers.size(); i++)
        {
            out_stream << passengers[i].get_first_name();
            out_stream << passengers[i].get_last_name();
            out_stream << passengers[i].get_phone_number();
            out_stream << passengers[i].get_seat_number();
            out_stream << passengers[i].get_seat_letter();
            out_stream << passengers[i].get_id_number();
        }
        out_stream << endl;
        out_stream.close();
        cout << "New data has been saved. " << endl;
    }
    else if(option == 'N' || 'N')
    {
        
    }
    else
    {
        cout << "Invalid input. Enter a character. ";
        cin >> option;
        while(cin.fail())
        {
            cout << "Invalid input. Enter a character.\n";
            cin.clear();
            cleanStandardInputStream();
            cin >> option;
        }
    }
    
}

void Flight::cleanStandardInputStream (void)
{
    int leftover;
    do
    {
        leftover = cin.get();
    } while (leftover !='\n' && leftover != EOF);
}

string Flight::add_white_space(const string& source, const int& size)
{
    int index = 0;
    int i;
    char new_str[size];
    
    while(source[index] != '\0')
    {
        index++;
    }
    index--;
    
    for(i = 0; i < source.length(); i++)
    {
        new_str[i] = source[i];
    }
    
    for(int j = i; j < size; j++)
    {
        new_str[j] = ' ';
    }
    
    return new_str;
}

