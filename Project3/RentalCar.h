//RYAN HOFFMAN - CS202 - PROJECT 3 - RentalCar.h
#ifndef RENTALCAR_H_
#define RENTALCAR_H_

class RentalCar{
	public:
	//CONSTRUCTORS
	RentalCar();
	RentalCar(int year, char * make, char * model, float price, bool available);
	
	//SET FUNCTIONS
	void setYear(int year);
	void setMake(char * make);
	void setModel(char * model);
	void setPrice(float price);
	void setAvailable(bool available);
	
	//GET FUNCTIONS
	int getYear() const;
	char * getMake();
	char * getModel();
	float getPrice() const;
	bool getAvailable() const;
	
	void printData() const;
	float estimateCost(int days) const;
	
	private:
	//PRIVATE VARIABLES
	int m_year;
	char m_make[256];
	char m_model[256];
	float m_price;
	bool m_available;
};
#endif
