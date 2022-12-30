/****SAMPLE PROGRAM HEADER*******************************************************
Oluwatumisesola Shoyoye    
Due Date:June 7th 2022 
Course:  C0P3014
Assignment:  Program 2
Professor: Tami Sorgente

Description: 
This program will calculate the tax , net cost and total cost of a sports equipment order using functions. 

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class

using namespace std;

void Greeting();

void GetDataInput(string &, string &, string &, int&, double&, int&);
//Preconditions: All variables must be declared before function is called
//PostConditions: All the order data for the order has been entered
//Description: Gets the informating for the order
void GetTaxRate(double&, int); 
//Preconditions: The location Id must be available to determine tax rate
//PostConditions:The tax rate will be determined
//Descriptions: Caluclates tax rate
void CalculateResults(int, double, double, double&, double&, double&);
//Preconditions: The tax rate and price must be avaialable
//PostConditions: The Net cost, total cost, and tax will be given. 
//Descriptions: Calculates the final price
void DisplayOutput(string, string, string, int, double, int, double, double, double, double);
//Preconditions: All variables must be already assigned and then printed to screen
//PostConditions: information will be printed to the screen
//Descriptions: Displays the reciept information 

int main()
{
	string userResponse = "y";
	string name, number, itemName, itemNum;
    int quantity, locationId; 
    double unitPrice, tax, taxRatelocal, netCost, totalCost; 

    Greeting();
    
	cout << "Enter your first name: ";
	cin >> name;

	while (userResponse != "n" && userResponse != "N")
	{
		//The code to get the user's input, perform the calculations, and print
        GetDataInput(number,itemName, itemNum, quantity, unitPrice, locationId);

       if(locationId <= 0 || locationId > 51)
       {
            cout << "Please enter a valid location ID between 1 and 51: "; 
            cin >> locationId; 
       }
       else GetTaxRate(taxRatelocal, locationId); //calls function to get taxrate

       CalculateResults(quantity, unitPrice , taxRatelocal, tax, netCost, totalCost); // call function to get results

       DisplayOutput(number, itemName, itemNum, quantity, unitPrice, locationId, taxRatelocal, netCost, tax, totalCost); //function call displays the reciept information
		// ask and get the userResponse 
        cout << name << " would you like to continue(Y or N)" << endl;
        cin >> userResponse;
	}
cout<< "Have a great day " << name;
	return  0;
}
void Greeting()
{
    cout << "Welome to the tax calculator app\n" << "You will be asked to enter random information for the item you wish to purchase\n";

}
//Description: Gets the informating for the order
void GetDataInput(string &numberRef, string &itemNameRef, string &itemNumRef, int &quantityRef, double &unitPriceRef, int &locationIdRef)
{
        cout << "\nEnter your phone number: "; 
        cin >> numberRef; 
        cout << "\nEnter the item name: "; 
        cin >> itemNameRef;
        cout << "\nEnter a random item number: ";
        cin >> itemNumRef; 
        cout << "\nEnter the quantity: "; 
        cin >> quantityRef; 
        cout << "\nEnter the price you wish to pay for this item: "; 
        cin >> unitPriceRef; 
        cout << "\nPlease enter a loation ID number (1-51): "; 
        cin >> locationIdRef; 
}

//Descriptions: Caluclates tax rate
void GetTaxRate(double &taxRate, int locationId)
{
        
        if(locationId == 1) // if else statement that tells us the tax rate
        {
            taxRate = 0.0725; 
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 2 && locationId <= 5)
        {
            taxRate = 0.07;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 6 && locationId <= 7)
        {
            taxRate = 0.0685;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 8 && locationId <= 15)
        {
            taxRate = 0.065;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 16 && locationId <= 27)
        {
            taxRate = 0.06;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 28 && locationId <= 33)
        {
            taxRate = 0.055;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 34 && locationId <= 35)
        {
            taxRate = 0.05;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 36 && locationId <= 40)
        {
            taxRate = 0.0445;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 41 && locationId <= 45)
        {
            taxRate = 0.04; 
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId == 46)
        {
            taxRate = 0.0290;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }
        else if(locationId >= 47 && locationId <= 51)
        {
            taxRate = 0.00;
            cout.precision(2); // keeps out double at two decimal places
            cout<< fixed;
            cout << "The Tax Rate is: " << taxRate << endl;
        }

}
//Descriptions: Calculates the final price
void CalculateResults(int quantity, double unitPrice , double taxRatelocal, double &taxRef, double &netCostRef, double &totalCostRef)
{
        taxRef = quantity * unitPrice * taxRatelocal; // calculates results
        netCostRef = quantity * unitPrice; // calculates results
        totalCostRef = netCostRef + taxRef; // calculates results
}
//Descriptions: Displays the reciept information 
void DisplayOutput(string number, string itemName, string itemNum, int quantity, double unitPrice, int locationId, double taxRatelocal, double netCost, double tax, double totalCost)
{
    cout << "Phone Number: " << number << endl;
    cout << "Item Name: " << itemName << endl; 
    cout << "Item Number: " << itemNum << endl; 
    cout << "Quantity: " << quantity << endl;
    cout << "Item Price: " << unitPrice << endl; 
    cout << "Location ID: " << locationId << endl; 

    cout.precision(2); // keeps out double at two decimal places
    cout<< fixed;
    cout << "Tax Rate: " << taxRatelocal << endl;

    cout.precision(2); 
    cout<< fixed;
    cout << "Net Cost: " << netCost << endl;
            
    cout.precision(2); 
    cout<< fixed;
    cout << "Order Tax: " << tax << endl; 

    cout.precision(2); 
    cout<< fixed;
    cout << "Total Cost: " << totalCost << endl;
}