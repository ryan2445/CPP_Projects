//Ryan Hoffman - CS202 - Project 4
#ifndef AGENCY_H_
#define AGENCY_H_

class Agency{
public:
Agency();
char * getName();
int getZipcode();
void setName(char * name);
void readAllData();
void printAllData();
void printAvailableCars();
void printFleetSensors();
void rentCar();
Car & operator[](const int index);
private:
char m_name[256];
int m_zipcode;
Car m_inventory[5];
};
#endif
