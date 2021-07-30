//main.cpp
//Created by: Gurpartap Sohi
//Ensf 337 Final Project
//Date: June. 15, 2020
//Lab Section: B01

#include <iostream>
#include "Flight.h"
void displayHeader();
int menu();
void pressEnter();

int main()
{
    Flight f;
    displayHeader();
    f.populate_flight_from_file("flight_info.txt");
    int choice;
    while((choice = menu()))
    {
        switch(choice)
        {
            case 1:
                f.display_map();
                pressEnter();
                break;
            case 2:
                f.display_passengers();
                pressEnter();
                break;
            case 3:
                f.add_passenger();
                pressEnter();
                break;
            case 4:
                f.remove_passenger();
                pressEnter();
                break;
            case 5:
                f.save_data("flight_info.txt");
                break;
            case 6:
                exit(1);
        }
    }
    return 0;
}

void pressEnter()
{
    cout << "\n<<< Press Return to Continue>>>>\n";
    cin.get();
    
}

int menu()
{
    int option;
    pressEnter();
    
    cout << "Please select one of the following options." << endl;
    cout << "1. Display Flight Seat Map." << endl;
    cout << "2. Display Passenger Information." << endl;
    cout << "3. Add A New Passenger." << endl;
    cout << "4. Remove An Existing Passenger." << endl;
    cout << "5. Save Data." << endl;
    cout << "6. Quit." << endl;
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, or 6) ";
    
    cin >> option;
    return option;
}

void displayHeader()
{
    cout << "Version: 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced: Gurpartap Sohi" << endl;
}

