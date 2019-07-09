// Harrison Lara
// April 9, 2017
// Program 5

#include "Employee.h" // include employee class(es)

void main()
{
	ifstream input("input.txt"); // open input file
	ofstream output("output.txt", ios::app); // open output file for appending

	Employee **emp; // create null pointer from parent class
	emp = new Employee *[100]; // create new parent class array of 100

	if (input.fail()) // check to see if input file opened or failed to open
	{
		cout << "Failed to open file!"; // error message foruser if failed
	}

	char hourly = 'H' || 'h'; // set hourly character to H or h
	char monthly = 'M' || 'm'; // set monthly character to M or m

	output << "Hourly and Monthly Employees:\n"; // output header
	while (input.eof()) // read file till end of file is reached
	{
		if (hourly) // loop if hourly employee
		{
			&HourlyEmployee::GetType; // call type function
			for (int i = 0; i < 101; i++) // loop for array of 100 for data collection
			{
				emp[i] = new Employee; //set array to parent class
				&HourlyEmployee::GetExpertEmployee; // find expert level 
				&HourlyEmployee::ReadData;//read through data
				&HourlyEmployee::WriteData; // write to output file
			}
		}
		else if(monthly)// loop if monthly employee
		{
			&MonthlyEmployee::GetType;// call type function
			for (int i = 0; i < 101; i++)// loop for array of 100 for data collection
			{
				emp[i] = new Employee; // set array to parent class
				&MonthlyEmployee::ReadData; // read through data
				&MonthlyEmployee::WriteData; // write to output file
			}
		}
		else //if monthly and hourly arent found, then report employee isnt found
		{
			cout << "Employee(s) not valid, closing file"; // error message
			input.close(); // close input file
			exit(1); // exit program
		}
	}
	// cout to screen for user the total amount of monthly and hourly employees
	cout << "Monthly Employees: \n" << "There are " << emp << " monthly employees\n" << "\nHourly Employees: " << "\nThere are " << emp << " hourly employees." << "\n";;

	ofstream sorted("sorted.txt"); // open new output file for sorted employee types
	sorted << "Monthly Employees: \n" << "There are " << &MonthlyEmployee::WriteData << " monthly employees\n" << "\nHourly Employees: " << "\nThere are " <<  &HourlyEmployee::WriteData << " hourly employees." << "\n";
	//output the sorted employees into a monthly list and then a hourly list of employees

	input.close(); // close output and inputs file
	sorted.close();
	output.close();
}