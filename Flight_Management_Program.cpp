// ENSF 337 Fall 2023 - Final Project
// Ryan Graham, Jaival Patel

#include <iostream>
using namespace std;
#include "Flight_Systems.h"

int main(void)
{
    cout << "Version: 2.4\nTerm Project - Flight Management Program in C++" << endl;
    cout << "Produced by: Ryan Graham and Jaival Patel\nYear: 2023\n" << endl;
    string a = "";
    do{
        cout << "<<< Press Return to Continue >>>" << endl;
        getline(cin, a);
    }while(a.length() != 0);
    Passenger Main;
    int num_of_clients = Main.Array();
    char num;
    while(1){
        num = run_menu();
        run_choice(num, Main, num_of_clients);
        if(num == '3'){num_of_clients += 1;}
        if(num == '4'){num_of_clients -= 1;}
    }
    return 0;
}