//Ryan Hoffman - CS202 - Project 4
#ifndef CAR_H_
#define CAR_H_
#include "Sensor.h"
class Car{
	
public:
Car();
Car(int year, char * make, char * model, float price, bool available, Sensor * sensorArr);
Car(Car & car);

char * getMake();
char * getModel();
int getYear();
Sensor * getSensors();
float getBasePrice();
float getFinalPrice();
bool getAvailable();
char * getOwner();

void setMake(char * make);
void setModel(char * model);
void setYear(int year);
void setBasePrice(float baseprice);
void setAvailable(bool available);
void setOwner(char * owner);

void updatePrice(float price);
void printData();
float estimateCost(int days);
Car & operator+(Sensor & sensor);
Car & operator+(char * lessee);

void totalSensors();

private:
char m_make[256];
char m_model[256];
int m_year;
Sensor m_sensors[3];
float m_baseprice;
float m_finalprice;
bool m_available;
char m_owner[256];	
};
#endif
