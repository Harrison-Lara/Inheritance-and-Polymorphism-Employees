// Harrison Lara
// April 9, 2017
// Program 5
#pragma once

//includes
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

#ifndef Employee

class Employee 
	/*Employee class is the main class which obtains the persons name,
	their id number and position type, then sets it. Then the repetitive functions 
	are reading the data from the files and writes it to the output file(s) */
{

public:

	string GetName() const; // name getter
	string GetId() const; // id getter
	void SetName(const string& NewName); // name setter
	void SetId(const string& NewId); // id setter
	virtual const bool ReadData(istream& input); // reads the data, then passes to setters when obtaining the correct data
	virtual const string GetType(); // reads and reports if the employee is hourly, monthly or doesnt exist
	virtual const bool WriteData(ostream&output); // writes the data to the output file

protected:
	string name = ""; // set name string to empty
	string id = ""; // set id string to empty
	string type = ""; // set type to empty
};

#endif // !Employee

#ifndef HourlyEmployee

class HourlyEmployee
	/*The hourly employee class is a dervived class of Employee and 
	does the exact same function as its parent, except it adds if the 
	employee is an expert in the field or not and gets their salary*/
{
public:
	// constructors
	HourlyEmployee();
	HourlyEmployee(string type, string name, string id, char expert, double salary);

	double GetSalary() const; // salary getter
	virtual string GetType(); // obtains what type of employee the person is
	bool setExpertEmployee(char NewExpert); // setter for if the employee is an expert or not
	bool SetSalary(double NewSalary); // setter for salary 
	virtual bool ReadData(istream& in); // reads and reports if the employee is hourly, monthly or doesnt exist
	virtual bool WriteData(ostream& out) const; // writes the data to the output file
	char GetExpertEmployee() const; // getter for expert type

protected:
	double salary; // salary variable
	char expert = 'F'; // default value for expert is false
};

#endif // !HourlyEmployee

#ifndef MonthlyEmployee

class MonthlyEmployee
	/* This Monthly employee is the exact same as its parents class Employee,
	except it inherits everything from Hourly and Employee classes and also
	adds on the persons rank*/
{

public:
	// constructors
	MonthlyEmployee();
	MonthlyEmployee(string type, string name, string id, char expert, int rank, double salary);

	virtual bool ReadData(istream& in);// reads and reports if the employee is hourly, monthly or doesnt exist
	virtual bool WriteData(ostream& out) const;// writes the data to the output file
	bool SetRank(int); // setter for the person ranking between 1 and 10
	virtual string GetType(); // getter for the employee type

protected:
	int rank = 10; // default rank is set to 10

};
#endif // !MonthlyEmployee

