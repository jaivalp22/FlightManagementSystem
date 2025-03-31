// Flight_Systems.h
// ENSF 337 Fall 2023 - Final Project
// Ryan Graham, Jaival Patel

#ifndef FLIGHT_SYSTEMS_H
#define FLIGHT_SYSTEMS_H

char run_menu();
//Formats menu and checks for user input for what they would like to do
//Returns number for menu choice

void run_choice(char num, class Passenger& Main, int num_of_clients);
//Recieves menu choice, excecutes any functions needed for their selectio

int verifyPhoneNumFormat(const string& phone_num);

class Passenger{

public:
    int Array();
    //Creates arrays for plane info and client info to be used elsewhere

    void save_to_file(int num_of_clients);
    //Saves current version of plane and client info to Flight_Info.txt with propper formatting

    string return_plane_info(int x);
    //Requires a number from 0-2, gives the string which exists in that part of the array for use

    string return_client_info(int x, int y);
    //Requires x for which client, y for what info is being requested, gives the string which exists in that part of the array for use

    void addNewPassenger(int num_of_clients);
    // This creates information for new Passenger and saves it to Flight_info.txt file

    void removeExistingPassenger(int num_of_clients);
    // This will remove a passenger's infromation from the Flight_info.txt file

    int findPassenger(const string& passengerId, int num_of_clients) const;

    void print_plane_map(int num_of_clients);

private:
    string plane_info[3];
    string trash; //Used to skip extra new lines in file which allows for better readability in text file
    string client_info[100][6];
    int i = 0;
    int j = 0;
};

#endif