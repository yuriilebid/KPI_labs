#include "lab3.h"
#include <iostream>

// using namespace std;

carry_truck* car1 = new carry_truck("Ford", 6, 249, 4000, 35000);

int show_menu() {
    int input = 0;

    cout << " Menu" << endl;
    cout << "1. Show objects" << endl;
    cout << "2. Increase power" << endl;
    cout << "3. Set value" << endl;
    cout << "4. Exit" << endl; 

    cin >> input;
    return input;
}

void set_handler(int input) {
    switch(input) {
        case 1: {
            int usage = 0;

            cout << "Enter usage: ";
            cin >> usage;
            car1->set_galons_use(usage);
        }
        case 2: {
            int power = 0;

            cout << "Enter power: ";
            cin >> power;
            car1->set_power(power);
        }
        case 3: {
            int weight = 0;

            cout << "Enter weight: ";
            cin >> weight;
            car1->set_max_weight(weight);
        }
        case 4: {
            int mileage = 0;

            cout << "Enter mileage: ";
            cin >> mileage;
            car1->set_miles_history(mileage);
        }
    }
}

void command_handler(int cmd) {
    if(cmd == 1) {
        car1->show_object();
    }
    else if(cmd == 2) {
        car1->increase_power(10);
    }
    else if(cmd == 3) {
        int input = 0;

        cout << "Which value?" << endl 
             << "1. Usage" << endl
             << "2. Power" << endl
             << "3. Max weight" << endl
             << "4. Mileage" << endl;
        cin >> input;
        set_handler(input);
    }
    else if(cmd == 4) {
        exit(0);
    }
}

int main() {
    cout << "Making truck with default constructor" << endl;
    carry_truck *base_car = new carry_truck();
    base_car->show_object();
    base_car->set_power(320);
    base_car->set_max_weight(15000);
    base_car->set_name("Mercedes");
    base_car->show_object();
    cout << endl;

    cout << "Making truck with constructor with parameters" << endl;
    carry_truck *normal_car = new carry_truck("Mercedes", 15, 480, 20000, 5000);
    normal_car->show_object();
    cout << endl;

    cout << "Making truck based on copy constructor" << endl;
    carry_truck *copy_car = new carry_truck(*normal_car);
    copy_car->show_object();
    cout << endl;

    delete base_car;
    delete normal_car;
    delete copy_car;
    delete car1;

    // while(true) {
    //     int cmd = show_menu();

    //     command_handler(cmd);
    // }
}