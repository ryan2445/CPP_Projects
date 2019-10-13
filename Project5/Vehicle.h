//Ryan Hoffman - CS202 - Project5
#ifndef VEHICLE_H_
#define VEHICLE_H_
class Vehicle{

//insertion operator overload
friend std::ostream & operator<<(std::ostream & os, Vehicle & vehicle);

public:
//consructors
Vehicle();
Vehicle(int vin, float * lla);
Vehicle(Vehicle & vehicle);
~Vehicle();

//assignment operator overload
Vehicle & operator=(Vehicle &vehicle);

//get functions
int getVin();
float * getLla();
static int getIdgen();

//set functions
void setLla(float * lla);
void setLla(const int lat, const int lng, const int alt);

//move function
void move(float *lla);

protected:
//protected variables
float m_lla[3];
int m_vin;

private:
//private static variable
static int s_idgen;
};

#endif
