#include <math.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include "lab3.h"

using namespace std;

#define MAXNAME 20

carry_truck::carry_truck(): galons_use(10), power(449), max_weight(35000), miles_history(0) {
	string exm = "Volvo";

    this->name = new char[MAXNAME];
    for(int i = 0; i < MAXNAME; i++) {
    	if(exm.size() > i)
    	    this->name[i] = exm[i];
    	else
    		this->name[i] = '\0';
    }
    cout << "Default constructor worked!" << endl;
}

carry_truck::carry_truck(const char* name, uint16_t galons_use_input, uint16_t power_input,
		    uint16_t max_weight_input, uint32_t miles_history_input) {
    this->name = new char[MAXNAME];

    if(strlen(name) > 0 && strlen(name) < 20) {
    	for(int i = 0; i < MAXNAME; i++) {
    	    if(strlen(name) > i)
    	        this->name[i] = name[i];
    	    else
    		    this->name[i] = '\0';
        }
    }
    else {
    	cout << "Wrong name length (0 < len < 20)" << endl;
    	exit(1);
    }
    if(galons_use_input > 0) {
        this->galons_use = galons_use_input;
    }
    else {
    	cout << "Wrong galon use (usage > 0)" << endl;
    	exit(1);
    }
    if(power_input > 0) {
        this->power = power_input;
    }
    else {
    	cout << "Wrong power (power > 0)" << endl;
    	exit(1);
    }
    if(max_weight_input > 0) {
        this->max_weight = max_weight_input;
    }
    else {
    	cout << "Wrong max_weight (max_weight > 0)" << endl;
    	exit(1);
    }
    if(miles_history_input > 0) {
        this->miles_history = miles_history_input;
    }
    else {
    	cout << "Wrong miles_history (miles_history > 0)" << endl;
    	exit(1);
    }
    cout << "Parameters done!" << endl;
}

carry_truck::carry_truck(const carry_truck &car) {
    this->name = new char[MAXNAME];
    *this = car;

    int len = 0;
    while (car.name[len++] != '\0') {}

    this->name = new char[len];
    for (int i = 0; i < len; i++)
        this->name[i] = car.name[i];

    cout << "Constructor of copy worked!" << endl;
}

carry_truck::~carry_truck() {
    delete [] this->name;
    cout << "Deleted object" << endl;
}

uint16_t carry_truck::get_galons_use() {
    return galons_use;
}

uint16_t carry_truck::get_power() {
    return power;
}

uint32_t carry_truck::get_miles_history() {
    return miles_history;
}

uint16_t carry_truck::get_max_weight() {
    return max_weight;
}

char* carry_truck::get_name() {
    return this->name;
}

void carry_truck::set_name(const char* name) {
    if(strlen(name) < 20 && strlen(name) > 0) {
    	for(int i = 0; i < MAXNAME; i++) {
    		if(strlen(name) > i)
    	        this->name[i] = name[i];
    	    else
    		    this->name[i] = '\0';
    	}
    }
    else {
    	cout << "Invalid name length" << endl;
    	exit(1);
    }
}

void carry_truck::set_galons_use(uint16_t input) {
    if(input < 0 || input > 255) {
        cout << "galons should be in range of 0 ... 255" << endl;
        exit(1);
    }
    galons_use = input;
}

void carry_truck::set_power(uint16_t input) {
    if(input < 0 || input > 65535) {
        cout << "power should be in range of 0 ... 65,535" << endl;
        exit(1);
    }
    power = input;
}

void carry_truck::set_miles_history(uint32_t input) {
    if(input < 0 || input > 2147483647) {
        cout << "miles should be in range of 0 ... 2,147,483,647" << endl;
        exit(1);
    }
    miles_history = input;
}

void carry_truck::set_max_weight(uint16_t input) {
    if(input < 0 || input > 65535) {
        cout << "weight should be in range of 0 ... 65,535" << endl;
        exit(1);
    }
    max_weight = input;
}

void carry_truck::increase_power(int value_to_increase) {
    if(value_to_increase < 0) {
        cout << "Value to increase couldnt be less than 0" << endl;
        exit(1);
    }
    power += value_to_increase;
}

void carry_truck::show_object() {
    cout << "   ID   |    Usage    |    Power   |    Max weight   |   Mileage  " << endl;
    cout << this->get_name() << "       " 
    << this->get_galons_use() << "            " 
    << this->get_power() << "           " 
    << this->get_max_weight() << "           " 
    << this->get_miles_history() << endl; 
}
