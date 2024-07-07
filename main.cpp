/*
 *  Name: Brian Pedroza
 *  Description: Program serves as a kiosk that can book first class, business class, economy class flights and displays price of tickets.
 *  Input: User selects desired ticket class and inputs number of desired tickets. User decides to continue buying more tickets or ending program.
 *  Output: Main menu displaying available tickets printed. Once class chosen user prompted for ticket amount. User prompted to continue or end program.
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int FIRST_CLASS {750};
const int BUS_CLASS {225};
const int ECON_CLASS {150};
const double TAX {0.0850};

int main()
{
    int firstSeats {15};
    int busSeats {25};
    int econSeats {50};
    string userSelection = "Speederman";
   
    do
    {
        int amountSelect {0};

        // Kiosk Main Menu & Flight Class Selection
        if (firstSeats > 0)
        {
            cout << "(F)irst\n";
        }
        if (busSeats > 0)
        {
            cout << "(B)usiness\n";
        }
        if (econSeats > 0)
        {
            cout << "(E)conomy\n";
        }
            cout << "Enter a selection: "
                 << endl;
                 
            cin >> userSelection;
         
         
        cout << fixed << setprecision (2);

           
        // First Class Selection
        if ((userSelection == "F") || (userSelection == "f"))
        {
            if (firstSeats <= 0)
            {
                continue;
            }
           

            // How many tickets: Input validity Check nested loop
            do
            {
                cout << "Enter amount:" << endl;
                cin >> amountSelect;
            
                // Correct input: Within parameters
                if ((amountSelect >= 0) && (amountSelect <= firstSeats))
                {
                
                    firstSeats -= amountSelect;
                        cout << "Cost $ " << amountSelect * FIRST_CLASS + (TAX * amountSelect * FIRST_CLASS) 
                             << endl;

                    break;
            
                }

                // Invalid input
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore (100000,'\n');
                }


            } while (true);
           
        }
       
        // Business Class Selection
        else if ((userSelection == "B") || (userSelection == "b"))
        {
            if (busSeats <= 0)
            {
                continue;
            }
           

            // How many tickets: Input validity Check nested loop
            do
            {
            
                cout << "Enter amount:" << endl;
                cin >> amountSelect;

                // Correct input: Within parameters
                if ((amountSelect >= 0) && (amountSelect <= busSeats))
                {
                
                    busSeats -= amountSelect;
                        cout << "Cost $ " << amountSelect * BUS_CLASS + (TAX * amountSelect * BUS_CLASS)
                             << endl;

                    break;
            
                }   

                // Invalid input
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore (100000,'\n');
                }


            } while (true);

           
        }
       
        // Economy Class Selection
        else if ((userSelection == "E") || (userSelection == "e"))
        {
            if (econSeats <= 0)
            {
                continue;
            }
           

            // How many tickets: Input validity Check nested loop
            do
            {
                cout << "Enter amount:" << endl;
                cin >> amountSelect;

                // Correct input: Within parameters
                if ((amountSelect >= 0) && (amountSelect <= econSeats))
                {
                
                    econSeats -= amountSelect;
                        cout << "cost $ " << amountSelect * ECON_CLASS + (TAX * amountSelect * ECON_CLASS)
                             << endl;

                    break;
            
                }

                // Invalid input
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore (100000,'\n');
                    }


            } while (true);
           
        }

        // Flight Class Invalid Input Check and Reset
        else
        {

            if (cin.fail())
            {

                cin.clear();
                cin.ignore(100000,'\n');
            
            }

            continue;
        }
       
     

        string offSwitch = "Sasquatch";

        // Shutdown prompt loop
        do
        {
        
        cout << "Shutdown? (Y/N): " << endl;
        cin >> offSwitch;

        if ((offSwitch == "Y") || (offSwitch == "y"))
        {
            return 0;
        }
        if ((offSwitch == "N") || (offSwitch == "n"))
        {
            break;
        }
        if (cin.fail())
        {

            cin.clear();
            cin.ignore(100000,'\n');
       
        } 
        } while (true);

        
   
    } while ((firstSeats > 0) || (busSeats > 0) || (econSeats > 0));
   

    return 0;
}