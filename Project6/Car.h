//Ryan Hoffman - CS202 - Project5
#ifndef CAR_H_
#define CAR_H_
#include "Vehicle.h"
class Car : public Vehicle {
	
public:
//constructors
Car();
Car(float * lla);
Car(Car & car);
virtual ~Car();

//assignment operator overload
Car & operator=(Car & car);

//get functions
int getThrottle();

//set functions
void setThrottle(int throttle);

//drive functon
void drive(int throttle);

//move function
virtual void Move(float * lla);
private:
//private data members
int m_throttle;
virtual void serialize(std::ostream & os);
};
#endif
