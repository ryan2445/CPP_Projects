//Ryan Hoffman - CS202 - Project5
#ifndef CAR_H_
#define CAR_H_
#include "Vehicle.h"
class Car : public Vehicle {

//insertion operator overload
friend std::ostream &operator<<(std::ostream &os, const Car &car);
	
public:
//constructors
Car();
Car(char * plates, int vin, float * lla);
Car(Car & car);
~Car();

//assignment operator overload
Car & operator=(Car & car);

//get functions
char * getPlates();
int getThrottle();

//set functions
void setPlates(char * plates);
void setThrottle(int throttle);

//drive functon
void drive(int throttle);

//move function
void move(float * lla);
private:
//private data members
char m_plates[256];
int m_throttle;
};
#endif
