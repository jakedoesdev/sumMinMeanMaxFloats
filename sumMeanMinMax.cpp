/*
Author:   	 Jacob Everett (jae0204)
Date:	  	 09/11/2018
Class:		 CSCE 1030.001
Professor:	 Mark Thompson
Description:     This program displays a menu, gets a choice from user, then takes 6 floating point numbers from user and performs one of 4 math operations on the numbers and
		 displays the result
*/

#include <iostream>
#include <stdio.h>

using namespace std;

//globally declared enum for menu options
enum MenuOption {SUM = 1, MEAN, MIN, MAX, EXIT};


int main() {
	
	float tempNum;			   	 	 //temporarily stores user-entered numbers until calculations can be performed
	float min = 3.40282e+038;  		 //stores minimum # in case MIN, initialized to highest possible float value
	float max = 1.17549e-038;  		 //stores maximum # in case MAX,initialized to lowest possible float value
	float calculatedNum = 0.0; 		 //stores calculated value in cases where calculation is needed
	const int NUMS_ACCEPTED = 6;     //constant that stores the number of floats accepted by program (changing this val to x allows program to accept x number of floats)
	int userChoice = 7; 	   		 //initialized to value that will hit default
	float divisor;				 	 //used to store the value of NUMS_ACCEPTED cast to a float when division is needed

	cout << "+------------------------------------------------+" << endl;
	cout << "|      Computer Science and Engineering          |" << endl;
	cout << "|       CSCE 1030 - Computer Science I           |" << endl;
	cout << "|   Jacob Everett   jae0204 jae0204@my.unt.edu   |" << endl;
	cout << "+------------------------------------------------+" << endl;
	
	//do while encompassing most of the program (exits only when userChoice == 5)
	//displays menu, gets userChoice, puts userChoice into switch
	do
	{

		//const variable used in menu so that it updates if const is changed
		cout << "+******************* M E N U ******************+" << endl;
		cout << "| 1. Compute sum of " << NUMS_ACCEPTED << " floating-point numbers   |" << endl;
		cout << "| 2. Compute mean of " << NUMS_ACCEPTED << " floating-point numbers  |" << endl;
		cout << "| 3. Compute min of " << NUMS_ACCEPTED << " floating-point numbers   |" << endl;
		cout << "| 4. Compute max of " << NUMS_ACCEPTED << " floating-point numbers   |" << endl;
		cout << "| 5. Exit                                      |" << endl;
		cout << "+**********************************************+" << endl;
		cout << "Please select option: ";
		
		//gets userChoice and casts to enum type MenuOption
		cin >> userChoice;
		userChoice = static_cast<MenuOption>(userChoice);

		//performs one of 5 actions depending on userChoice.
		switch (userChoice)
		{
			
			//sums and outputs 6 user-entered floats if userChoice is 1
			case SUM:
				cout << "You have chosen sum.\nYou will now be prompted to enter " << NUMS_ACCEPTED << " numbers.\n";
								
				//loops NUMS_ACCEPTED number of times. Each iteration displays "Number i: ", gets user-entered tempNum,
				//and stores tempNum + calculatedNum in calculatedNum.
				for (int i = 1; i <= NUMS_ACCEPTED; ++i)
				{
					cout << "Number " << i << ": ";
					cin >> tempNum;
					calculatedNum = tempNum + calculatedNum;
				}
			
				//outputs calculatedNum
				cout << "The sum of the " << NUMS_ACCEPTED << " numbers is: " << calculatedNum << "." << endl;

				//reset calculatedNum and tempNum to 0.0 for next loop
				calculatedNum = 0.0;
				tempNum = 0.0;
				break;
				
			//finds and outputs mean of 6 user-entered floats if userChoice is 2
			case MEAN:
				cout << "You have chosen mean.\nYou will now be prompted to enter " << NUMS_ACCEPTED << " numbers.\n";
				
				//loops NUMS_ACCEPTED number of times. Each iteration displays "Number i: ", gets user-entered tempNum,
				//and stores tempNum + calculatedNum in calculatedNum.
				for (int i = 1; i <= NUMS_ACCEPTED; ++i)
				{
					cout << "Number " << i << ": ";
					cin >> tempNum;
					
					calculatedNum = tempNum + calculatedNum;
				}
				
				//casts the int stored in NUMS_ACCEPTED to a float, then divides calculatedNum by divisor to find mean
				//(I originally had declared NUMS_ACCEPTED as a float and used that to divide but I figured that was bad practice)
				divisor = static_cast<float>(NUMS_ACCEPTED);
				calculatedNum = calculatedNum / divisor;
					
				//outputs calculatedNum
				cout << "The mean of the " << NUMS_ACCEPTED << " numbers is: " << calculatedNum << "." << endl;
				
				//reset calculatedNum, tempNum, and divisor to 0.0 for next loop
				calculatedNum = 0.0;
				tempNum = 0.0;
				divisor = 0.0;
				break;
				
			//finds and outputs min of 6 user-entered floats if userChoice is 3
			case MIN:
				cout << "You have chosen min.\nYou will now be prompted to enter " << NUMS_ACCEPTED << " numbers.\n";
				
				//loops NUMS_ACCEPTED number of times. Each iteration displays "Number i: ", gets user-entered tempNum,
				//and compares against min. if loop checks each tempNum against min and replaces min if tempNum is smaller
				for (int i = 1; i <= NUMS_ACCEPTED; ++i)
				{
					cout << "Number " << i << ": ";
					cin >> tempNum;
					if (min > tempNum)
					{
						min = tempNum;
					}
				}
				
				cout << "The min of the " << NUMS_ACCEPTED << " numbers is: " << min << "." << endl;
				
				//reset min to highest possible float value for next loop
				min = 3.40282e+038;
				break;
				
			//finds and outputs max of 6 user-entered floats if userChoice is 4
			case MAX:
				cout << "You have chosen max.\nYou will now be prompted to enter " << NUMS_ACCEPTED << " numbers.\n";

				//loops NUMS_ACCEPTED number of times. Each iteration displays "Number i: ", gets user-entered tempNum,
				//and compares against max. if statement checks each tempNum against max and replaces max if tempNum is larger
				for (int i = 1; i <= NUMS_ACCEPTED; ++i)
				{
					cout << "Number " << i << ": ";
					cin >> tempNum;
					if (max < tempNum)
					{
						max = tempNum;
					}
				}
	
			        cout << "The max of the " << NUMS_ACCEPTED << " numbers is: " << max << "." << endl;
				
				//reset max to lowest possible float value for next loop
				max = 1.17549e-038;
				break;
				
			//outputs goodbye message and exits program if userChoice is 5
			case EXIT:
			
				cout << "Thank you for using this program. Good bye!" << endl;
				break;
				
			//outputs error message until userChoice is between 1 and 5 (non-numeric input results in infinite loop)		
			default:
			
				cout << "(" << userChoice << ") is invalid, please enter a number 1 - 5" << endl;
				break;
		}

	//loop repeats until userChoice == 5		
	} while (userChoice != 5);

return 0;

}
