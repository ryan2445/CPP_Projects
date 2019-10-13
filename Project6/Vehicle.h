//Ryan Hoffman - CS202 - Project5
#ifndef VEHICLE_H_
#define VEHICLE_H_
class Vehicle{
friend std::ostream & operator<<(std::ostream & os, Vehicle & vehicle);
public:
//consructors
Vehicle();
Vehicle(float * lla);
Vehicle(Vehicle & vehicle);
virtual ~Vehicle();

//assignment operator overload
Vehicle & operator=(Vehicle &vehicle);

//get functions
float * getLla();

//set functions
void SetLLA(float * lla);
void SetLLA(const int lat, const int lng, const int alt);

//move function
virtual void Move(float *lla)=0;
protected:
//protected variables
float m_lla[3];

private:
virtual void serialize(std::ostream & os);
};

#endif
