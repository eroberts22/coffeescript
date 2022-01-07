#include <iostream>
#include <time.h>
#include <chrono>
#include <Windows.h>
using namespace std;

//variables////////////////////////
int water_amount = 30;
bool power = false;
int amount = 4;
enum Strength {regular,strong,iced};
Strength strength = regular;
string no_water = "Not enough water to brew ";
time_t t = time(0);
tm *local_time = localtime(&t);
///////////////////////////////////

//to string for strength enum
string str(Strength s) {
switch(s) {
    case regular: return "regular";
    case strong: return "strong";
    case iced: return "iced";
    default: return "regular";
   }
}

int main() {

//turn power on
power = true;

//display time
t = time(0);
local_time = localtime(&t);
cout << "Current Time: " << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << endl;

//set amount
amount = 4;

//set strength
strength = regular;

//brewing
if (amount < water_amount) {
    water_amount = water_amount - amount;
    cout << "Brewing...\n";
    Sleep(1000);
    cout << amount << " ounce " << str(strength) << " coffee is ready!\n";
} else { cout << no_water << amount << " ounce coffee!\n";}

//set amount
amount = 16;

//set strength
strength = strong;

//brewing
if (amount < water_amount) {
    water_amount = water_amount - amount;
    cout << "Brewing...\n";
    Sleep(1000);
    cout << amount << " ounce " << str(strength) << " coffee is ready!\n";
} else { cout << no_water << amount << " ounce coffee!\n";}

//set strength
strength = iced;

//set amount
amount = 8;

//brewing
if (amount < water_amount) {
    water_amount = water_amount - amount;
    cout << "Brewing...\n";
    Sleep(1000);
    cout << amount << " ounce " << str(strength) << " coffee is ready!\n";
} else { cout << no_water << amount << " ounce coffee!\n";}

//set amount
amount = 20;

//brewing
if (amount < water_amount) {
    water_amount = water_amount - amount;
    cout << "Brewing...\n";
    Sleep(1000);
    cout << amount << " ounce " << str(strength) << " coffee is ready!\n";
} else { cout << no_water << amount << " ounce coffee!\n";}

//display time
t = time(0);
local_time = localtime(&t);
cout << "Current Time: " << local_time->tm_hour << ":" << local_time->tm_min << ":" << local_time->tm_sec << endl;

//turn power off
power = false;

}
