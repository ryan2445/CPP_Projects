//RYAN HOFFMAN - CS202 - Project 3 - RentalAgency.h
#ifndef RENTALAGENCY_H_
#define RENTALAGENCY_H_
#include "RentalCar.h"

//RENTAL AGENCY STRUCT
struct RentalAgency{
	char name[256];
	int zipcode[5];
	RentalCar inventory[5];
};
#endif
