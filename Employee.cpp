// Harrison Lara
// April 9, 2017
// Program 5

#include "Employee.h" // include employee class(es)

ifstream input("input.txt"); // open input file
ofstream output("output.txt", ios::app); // open outfile for appending 

string Employee::GetName() const { return name; } // getter returns employee name

string Employee::GetId() const { return id; } // getter returns employee id number

void Employee::SetName(const string & NewName) { name = NewName; } // setter for name passed to new name

void Employee::SetId(const string & NewId) { id = NewId; } // setter id passed to newID

const bool Employee::ReadData(istream& input) 
// this function return true if type, name and id of employee is found, false is not found
{
	string type = ""; // set type to empty string
	if (input.fail()) // check to make sure the input file is opened and is found
	{
		cout << "Failed to open file!"; // error message if file is not found
	}

	if (input)
	{
		while (input.good()) // read input file to the end
		{
			input >> type // get type from input file
				>> name// get name from input file
				>> id;// get id from input file
			return true; // returns true if completed with data
		}
	}
	else
		return false; // returns false if data not obtained
}

const string Employee::GetType() // getter for the employee type
{
	string emp_type = "Employee"; // reports if the person is an employee or not
	output << emp_type; // output if employee
	return emp_type;
}

const bool Employee::WriteData(ostream &output) // returns true or false if data was outputted or not correctly
{
	if (output)
	{
		output << type << "\n" << name << "\n" << id << "\n"; // output the employee type, name and id to the file
		return true;
	}
	else
		return false; // return false if failure to process data
}

HourlyEmployee::HourlyEmployee() : HourlyEmployee("", "", "", 'F', -1) {}; // constructor for hourly employee

HourlyEmployee::HourlyEmployee(string type, string name, string id, char expert, double salary)// constructor for hourly employee
{
	type = ""; // set to default value empty
	name = "";// set to default value empty 
	id = "";// set to default value empty
	expert = 'F';// set to default value of False
	salary = 0.0;// set to default value of 0

}

double HourlyEmployee::GetSalary() const
{
	return salary; // this function returns the value of salary for each employee
}

string HourlyEmployee::GetType()// getter for the employee type
{
	string emp_type = "Hourly Employee";// reports if the person is an hourly employee or not
	output << emp_type;// output if employee is hourly
	return emp_type;
}

bool HourlyEmployee::setExpertEmployee(char NewExpert) //this function sets expert to True (T) if a T is found
{
	if (char expert = 'T') // set expert to True if T
		expert = NewExpert; // set new value to New expert
		return true;
}

bool HourlyEmployee::SetSalary(double NewSalary) // sets the salary for each employee if within range
{
	if (salary >= 1000 && salary <= 10000) // value of salary must be between 1,000 and 10,000
		return true; // returns true if within range and false if not
	else
		return false;
}

bool HourlyEmployee::ReadData(istream & in) //function reads the data and checks for file failure, then gets the employees expert character and salary
{
	if (input.fail()) // check to see if file opened or failed to open
	{
		cout << "Failed to open file!"; // report the file didnt open with error message
	}

	if (input)
	{
		while (input.good()) // read entire file of unknown length
		{
			input >> expert // get the expert character for each employee
				>> salary; // get the salary for each employee
			return true;
		}
	} // return false if data was not obtained
	else
		return false;
}

bool HourlyEmployee::WriteData(ostream & out) const // writes the data to the output file and returns true or false if done so correctly
{
	if (output)
	{
		&Employee::WriteData; // write data from Employee class
		output << expert << "\n" << salary << "\n"; // now append the new data for the employee ( expert level and salary)
		return true;
	}
	else 
	{
		return false; // return false if output failed
	}
}

char HourlyEmployee::GetExpertEmployee() const // retrieves the type for each employee if expert or not
{
	char type; // set type to character
	if (type = 'T') // if true then (T), then return true
		return true;
	else // return false if T is not found
		return false;
}

MonthlyEmployee::MonthlyEmployee() : MonthlyEmployee("", "", "", 'F', -1, -1) {}; // constructor for Monthly Employee

MonthlyEmployee::MonthlyEmployee(string type, string name, string id, char expert, int rank, double salary)// constructor for Monthly Employee
{
	type = ""; //set to default value to empty
	name = "";//set to default value to empty
	id = "";//set to default value to empty
	expert = 'F';//set to default value to false
	rank = 10;//set to default value to ten
	salary = 0.0;//set to default value of zero

}

bool MonthlyEmployee::ReadData(istream & in) // reads the data to find the rank of an employee
{
	if (input.fail()) // checks to see if file failed or not to open
	{
		cout << "Failed to open file!"; // error message if failed to open
	}
	if (input)
	{
		while (input.good()) // read to end of file of unknown size
		{
			input >> rank; // grab the rank
			return true;
		}
	} // return false if rank not grabbed
	else
		return false;
}

bool MonthlyEmployee::WriteData(ostream & out) const // write the data from previous clases and add on the rank for each employee
{
	if (output)
	{
		&Employee::WriteData; // write output from Employee
		&HourlyEmployee::WriteData; // write output from hourly employees
		output << rank << "\n"; // then outputs the rank for each employee
	}
	return false; // return false if data didnt output
}

bool MonthlyEmployee::SetRank(int) // sets the rank to a range, or returns false if outside of range
{
	if (rank >= 1 && rank <= 10) // return true if rank is between 1 and 10
		return true;
	else // return false if rank is below 1 or above 10
		return false;
}

string MonthlyEmployee::GetType() // function reports if the employee is monthly
{
	string emp_type = "Monthly Employee"; // reports if the person is an monthly employee or not
	output << emp_type; // out that employee is monthly
	return emp_type;

}
