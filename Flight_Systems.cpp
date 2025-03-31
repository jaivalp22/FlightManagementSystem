// Flight_Systems.cpp
// ENSF 337 Fall 2023 - Final Project
// Ryan Graham, Jaival Patel
#include <climits>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
#include "Flight_Systems.h"

char run_menu(){
    string num = "";
    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passenger Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove an Existing Passenger" << endl;
    cout << "5. Save Data" << endl;
    cout << "6. Quit" << endl;

    while(1){
        cout << "\nEnter your choice: (1, 2, 3, 4, 5 or 6) ";
        cin >> num;
        if(num[0] >= '1' && num[0] <= '6'){break;}
        else{cout << "\nError, number isn't valid.";}
    }
    cout << num[0] << '\n' << endl;
    return num[0];
}

void run_choice(char num, class Passenger Main, int num_of_clients){
    if(num == '1'){
        
    }
    if(num == '2'){
        int k = 0;

		cout << "First Name          Last Name           Phone               Row  Seat ID\n";
		cout << "---------------------------------------------------------------------------\n";

		while (k <= num_of_clients) {
			cout << left << setw(20) << Main.return_client_info(k, 0);
			cout << left << setw(20) << Main.return_client_info(k, 1);
			cout << left << setw(20) << Main.return_client_info(k, 2);
			cout << left << setw(5) << Main.return_client_info(k, 3);
			cout << left << setw(5) << Main.return_client_info(k, 4);
			cout << left << Main.return_client_info(k, 5) << endl;

			cout << "---------------------------------------------------------------------------\n";
			k++;
    }

		cout << endl;
		string a = "";
		getline(cin, a);
		do {
			cout << "<<< Press Return to Continue >>>" << endl;
			getline(cin, a);
    } 	while (a.length() != 0);
		cout << endl;
    }
    if(num == '3'){
        Main.addNewPassenger(num_of_clients);
        cout << endl;
        string a ="";
        do{
            cout << "<<< Press Return to Continue >>>" << endl;
            getline(cin,a);
        
        }while(a.length() != 0);
        cout << endl;
    }
    if(num == '4'){
        Main.removeExistingPassenger(num_of_clients);
        cout << endl;
        string a ="";
        do{
            cout << "<<< Press Return to Continue >>>" << endl;
            getline(cin,a);
        
        }while(a.length() != 0);
        cout << endl;
    }
    if(num == '5'){
        string a = "";
        while(1){
        cout << "Do you want to save the data in the \"Flight_Info.txt\"? Please answer <Y or N>: ";
        cin >> a;
        if(a == "N"){cout << "File was not saved.\n" << endl; return;}
        else if(a == "Y"){Main.save_to_file(num_of_clients); return;}
        else{cout << "Error, input isn't valid. Try Again:\n" << endl;}
        }
    }
    if(num == '6'){cout << "Program Terminated."; exit(1);}
}

int Passenger::Array() {
    ifstream input;
    input.open("Flight_Info.txt");

    if (input.fail()) {
        cout << "Error opening file...quitting\n";
        input.close();
        exit(1);
    }

    string totalRowsStr, totalColumnsStr;

    input >> plane_info[0] >> plane_info[1] >> plane_info[2];

    
    int totalRows = stoi(plane_info[1]);
    int totalColumns = stoi(plane_info[2]);

    
    getline(input, trash);

    int i = 0; 

    while (i < totalRows * totalColumns) {
        string line;
        if (!getline(input, line)) {
            break; 
        }

        istringstream iss(line);

        
        string firstName, lastName, phone, row, seat, passengerID;

        
        iss >> firstName;

        
        while (iss >> lastName && !isdigit(lastName[0])) {
            firstName += " " + lastName;
        }

        
        iss >> phone >> row >> seat >> passengerID;

        
        client_info[i][0] = firstName;
        client_info[i][1] = lastName;
        client_info[i][2] = phone;
        client_info[i][3] = row;
        client_info[i][4] = seat;
        client_info[i][5] = passengerID;

        
        i++;
    }

    cout << "Read and recorded info." << endl;
    input.close();
    return i;
}

void Passenger::save_to_file(int num_of_clients){
    ofstream output;
    output.open("Flight_Info.txt");

    if(output.fail()){
        cout << "Error opening file...quitting\n";
        output.close();
        exit(1);
    }

    for(int i=0; i<3; i++){
        output << plane_info[i] << endl;
    }
    i=0;
    j=0;
    while((num_of_clients+1) != j){
        if(i == 6){i = -2; j += 1;}
        else if(i==-1){output << endl;}
        else{
            output << "\n" << client_info[j][i];
        }
        i += 1;
    }
    cout << "\nAll the data in the passenger list was saved into the \"Flight_Info.txt\".\n" << endl;
    output.close();
}

string Passenger::return_plane_info(int x){
    return plane_info[x];
}

string Passenger::return_client_info(int x, int y){
    return client_info[x][y];
}

void Passenger::addNewPassenger(int num_of_clients) {
    string passengerId;

    cout << "Please enter the passenger id: ";
    while (!(cin >> passengerId) || findPassenger(passengerId, num_of_clients) != -1) {
        cout << "Invalid input or passenger with ID " << passengerId << " already exists. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    cout << "Please enter the passenger first name: " << endl;
    string firstName;
    cin >> firstName;
    

    cout << "Please enter the passenger last name: " << endl;
    string lastName;
    cin >> lastName;

    cout << "Please enter the passenger phone number: " << endl;
    string phone;
    cin >> phone;

    int row;
    while(true) {
        cout << "Enter the passenger's desired row: " << endl;
        if(cin >> row) {
            break;
        
        }  else {
            cout << "Invalid input. Please try again.\n" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    
    }
   
    cout << "Enter the passenger's desired seat: " << endl;
    char seat;
    while(true) {
        if(cin >> seat) {
            break;
        
        }  else {
            cout << "Invalid input. Please try again.\n" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
    ++num_of_clients;
    client_info[num_of_clients][0] = passengerId;
    client_info[num_of_clients][1] = firstName;
    client_info[num_of_clients][2] = lastName;
    client_info[num_of_clients][3] = phone;
    client_info[num_of_clients][4] = to_string(row) + seat;
    client_info[num_of_clients][5] = to_string(10000 + num_of_clients + 1);

    ++num_of_clients;

    cout << "Passenger " << passengerId << " added successfully.\n" << endl;

}

void Passenger::removeExistingPassenger(int num_of_clients) {
    while(true) {
        cout << "Please enter the passenger id to remove: " << endl;
        string passengerId;
        cin >> passengerId;

            for(int k = 0;k <= num_of_clients; ++k) {
                if (client_info[k][5] == passengerId)  {
                    client_info[k][0] = client_info[num_of_clients][0];
                    client_info[k][1] = client_info[num_of_clients][1];
                    client_info[k][2] = client_info[num_of_clients][2];
                    client_info[k][3] = client_info[num_of_clients][3];
                    client_info[k][4] = client_info[num_of_clients][4];
                    client_info[k][5] = client_info[num_of_clients][5];

                    client_info[num_of_clients][0] = "";
                    client_info[num_of_clients][1] = "";
                    client_info[num_of_clients][2] = "";
                    client_info[num_of_clients][3] = "";
                    client_info[num_of_clients][4] = "";
                    client_info[num_of_clients][5] = "";

                    --num_of_clients;

                    cout << "Passenger " << passengerId << " removed successfully.\n" << endl;

                    
            
                    return;
                }
            }

    cout << "Passenger with ID " << passengerId << " not found. Cannot remove non-existing passenger.\n" << endl;
        

    }

}

int Passenger::findPassenger(const string& passengerId, int num_of_clients) const {
    for (int k = 0; k <= num_of_clients; ++k) {
        if (client_info[k][0] == passengerId) {
            return k;
        }
    }
    return -1;
}