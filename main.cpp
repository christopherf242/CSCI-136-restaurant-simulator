#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


class Branch //For each specific branch.
{
public:
    void setEmployees(); //Sets the names of the waiters and the amount of the waiters
    void setManager(string m);
    // Ceo/user sets the same of the string manager of the Branch object
    string getManagerName( ); //This will be used to output the name of the manager for each branch
    void displayEmployees(); // The manager displays the employees
    Branch(int address); //Each branch
    Branch( );
    void setBranchAddress(int addressNew);
private:
    int address;
    string manager; //The manager sets the prices for the items
    vector<string> employees; //The waiter will help to display the details of the item

};

class Item
{ //For each specific food item
public:
  Item( ); //Default constructor that will be initialized throu
  Item(double priceNew, double caloriesNew, string itemNameNew); //Constructor with the member variables initialized by the arguments when called
                                            //in the main function
  void setCalories(double newCalories); //Used by Ceo in the setMenu member function
  double getCalories( ); //Used to display the calories
  double getPrice( ); //Used to display the calories
  void setItemName(string itemNameNew ); //Used by the Ceo in the setMenu member function
  string getItemName( ); //Used to display the name


private:
  double price; //Of the type Money
  double calories;
  string itemName;
};

class Restaurant //Prototype of restuarant, the whole restaurant Food chain(Burger King)
{
public:
    Restaurant( ); //Default constructor
    /* Member functions that were created while making the program but not used */
    void setCeo(string ceo); //Gets user to set the name of the ceo of the whole food chain
    string getCeo( ); //This allow us to display the name of the ceo

    void setMenu();
    //Ceo sets the menu, using a for loop with cin menu at index position in for loop.
    void explainItemDetails(); //Displays the details of each item on the menu
    void displayItemMenu( ); //Displays the items on the menu
    void addIngredients(); //The employee/cook adds the ingredients
    void checkIngredients(); //The waiter checks the ingredients

private:
    vector <Item> menu;
    //An array for the menu of class type menu, we will use member functions from the class Item inside member functions
    // in member functions of the type Restaurant
    string ceo;
    vector<string> ingredients; //The ingredients are the same for the whole restaurant
    //for employee to cook and is checked by the manager
    /* Member variable was created while making the program, but not used   */
    Branch b[1];
};

int main()
{//while equal to 4 we break out of the loop
    int choice,func;
    Branch manhattanBranch;
    Restaurant burgerKing;
    Item food;
    string nameOfManager, restaurantName;
    int branchAddress;
    cout << "\n What would you like to name your restaurant: ";
    getline(cin, restaurantName);
    cout << "\n The restaurant name is: " << restaurantName << endl;

    while(true){ //True means that it goes until we have an exit(not a break)
        cout << "Welcome to " << restaurantName << endl;
        cout << "Please enter 1 if ceo , 2 if manager, enter 3 if employee, enter 4 for exit" << endl;
        cin >> choice;
        if(choice == 4){
            exit(0);
        }
        while(choice == 1){ //while loop used instead of an if statement

            cout << "\nI am a CEO, enter 1 to enter the address of the restaurant branch," << endl;
            cout <<  "enter 2 the name of the manager of the branch," << endl;
            cout << "enter 3 to set the menu," << endl;
            cout << "enter 4 to go back to main menu" << endl;
            cin >> func;
            if(func == 4)
            {
                cout << "\nGoing back to the main menu" << endl;
                break;
            }


            switch(func)
            {

                case 1:

                    cout << endl;
                    cout << "Please enter the address of the restaurant branch as an integer: ";
                    cin >> branchAddress;
                    manhattanBranch.setBranchAddress(branchAddress);
                    break;

               case 2:

                    cout << "\ndoing 2" << endl;
                    cout << "Enter the name of the manager of the branch that needs a manager: ";
                    cin >> nameOfManager;
                    manhattanBranch.setManager(nameOfManager);
                    break;

               case 3:

                    cout << "\nSetting the menu." << endl;
                    burgerKing.setMenu();
                    break;
                default:

                    cerr << "\nInvalid range, please enter another value" << endl;
            }
        }
        //end smaller while loop
        while(choice == 2){

             cout << "\nI am a manager, enter 1 to set the employees ";
            cout << "enter 2 to display your employees, enter 3 check the ingredients, " << endl;
            cout << "enter 4 to do back to main menu" << endl;
            cin >> func;

            if(func == 4)   //exits the while loop if the user chooses 4
            {
                cout << "\nGoing back to the main menu" << endl;
                break;
            }

            switch(func)
                {
                case 1:
                    cout << "\ndoing 1, setting the employees" << endl;


                    manhattanBranch.setEmployees();
                break;
                case 2:
                    cout << "\nDoing 2, printing out the employees" << endl;
                    manhattanBranch.displayEmployees();
                break;
                case 3:
                    cout << "\nChecking the ingredients: " << endl;
                    burgerKing.checkIngredients();
                    cout << endl;

                break;
                default:
                    cerr << "\nReturning to menu: " << endl;



            }
        }
         while(choice == 3){
            cout << "\nI am an employee, enter 1 to display the menu , enter 2 to explain the description of the menu items";
            cout << ", enter 3 to add new ingredients, enter 4 to do back to main menu" << endl;
            cin >> func;

            if(func == 4)
            {
                cout << "\nGoing back to the main menu" << endl;
                break;
            }

            switch(func)    //Original condition func != 3 since going to menu was the 3rd option
                {
                case 1:
                    cout << "\nHere's the menu: " << endl;
                   // Also create int variable equal to 3 since we already have 3 items(can check that)
                   //Then we increment that argument by 1 inside the function
                    burgerKing.displayItemMenu( );
                break;
                case 2:
                    cout << "\nExplaining the calories and cost of the menu items to the customers:" << endl;
                    burgerKing.explainItemDetails();

                 break;
                case 3:

                    burgerKing.addIngredients();
                break;
                default:
                    cerr << "\nReturning to menu: " << endl;

                }

            }
        }

    return 0;
}

Branch::Branch( )
    :address(0)
{
    string employee1, employee2, employee3;
    employee1 = "Jimmy";
    employee2 = "Felipe";
    employee3 = "Joe";
    employees.push_back(employee1);
    employees.push_back(employee2);
    employees.push_back(employee3);
}

Branch::Branch(int addressNew)
    :address(addressNew)
{
    string employee1, employee2, employee3;
    employee1 = "Jimmy";
    employee2 = "Felipe";
    employee3 = "Joe";
    employees.push_back(employee1);
    employees.push_back(employee2);
    employees.push_back(employee3);
}
//For the item class
Item::Item( )
    :price(0), calories(0), itemName( "No name")
{

}

Item::Item(double priceNew, double caloriesNew, string itemNameNew)
    :price(priceNew), calories(caloriesNew), itemName(itemNameNew)
{

}

Restaurant::Restaurant()
    :ceo("No Name")
{

        Item Fries(2.50, 100, "Fries");
        Item whopper(4.99, 250, "whopper");
        Item chickenTenders(3.00, 150, "chickenTenders");
        menu.push_back(Fries);
        menu.push_back(whopper);
        menu.push_back(chickenTenders);

        string ingredients1, ingredients2, ingredients3;
        ingredients1 = "pepper";
        ingredients2 = "barbecueSauce";
        ingredients3 = "lettuce";
        ingredients.push_back(ingredients1);
        ingredients.push_back(ingredients2);
        ingredients.push_back(ingredients3);
}
 void Branch::setBranchAddress(int addressNew)
 {
     address = addressNew;
 }
void Branch::setEmployees()
 {  //We don't need an extra parameter for int numberOfEmployees since we just use the size of the vector
    //in the for loop
   string employeeName;
   int numberOfEmployees;
    cout << "How many employees do you want to add? " << endl;
    cout << "The max amount is 10 employees: ";
    cin >> numberOfEmployees;
    cout << endl << "Adding " << numberOfEmployees << " employees." << endl;
   for(int index = 0; index < numberOfEmployees; index++)
   {
       cout << "\nName of employee" << index + 1 << ": ";
       cin >> employeeName;
       employees.push_back(employeeName);

       //don't need numOfEmployees++;
   }

    cout << "You added these employees: " << endl;
            //Index equals 3 to start at the vector where we added the employees to the already existing 3 employees
    for(unsigned int index = 3; index < employees.size(); index++)
    {

            cout << "Worker " << index << ": " << employees[index] << endl;
 }

 }

void Branch::displayEmployees()
{
    cout << "\nDisplaying all of the employees that work at Burger King: " << endl;
    for(unsigned int index = 0; index < employees.size(); index++)
   {
       cout << "Employee #" << index + 1 <<  ": " << employees[index] << endl;
   }
}

void Branch::setManager(string m)
 {
     manager = m;
     cout << "\nName of the manager of this branch: " << manager << endl;
 }

 string Branch::getManagerName( )
 {
     return manager;
 }


void Item::setCalories(double newCalories )
{
    calories = newCalories;
}

double Item::getCalories( )
{
    return calories;
}

double Item::getPrice( )
{
    return price;
}

void Item::setItemName(string itemNameNew )
{
    itemNameNew = itemName;
}

string Item::getItemName( )
{
    return itemName;
}
void Restaurant::setMenu() //Do a ton of similar functions, some that include ingredients, displaying menu, also then getTip
{                                                   //
   // int menuSize;
    string userInputName;
    double theCalories, theCost;
    cout << "\nPlease add 1 item to our menu, which is currently frenchFries, whopper, and chicken tenders." << endl;


        cout << "Name of item: ";
        cin >> userInputName;
        cout << endl;
        cout << "How many calories does your item contain: ";
        cin >> theCalories; // A double value
        cout << endl;
        cout << "How much does your item cost: $";
        cin >> theCost; //A double value
        cout << endl;

        Item temporary(theCost, theCalories, userInputName);
        menu.push_back(temporary);

}

void Restaurant::displayItemMenu()
{
    cout << endl << "****************Menu**************************" << endl;
    //We cout the menu in the main function, for this we don't append the
        string theItemName;
        for(unsigned int i = 0; i < menu.size(); i++)
        {   //We used the menu.size() function since we didn't pop back/increase the size of the vector

        theItemName = menu[i].getItemName();
        cout << "Food # " << i+1 << theItemName << endl;
        }

    cout << "************************************************" << endl;
    cout << "Thank you for coming to our restaurant!" << endl;
}

void Restaurant::checkIngredients()
{   cout << "***********Ingredients**********" << endl;
    cout << "These are the current ingredients: "  << endl;
    for(unsigned int i = 0; i < ingredients.size(); i++)
    {
        cout << "Ingredient #" << i + 1 << ": " << ingredients[i] << endl;
    }

}

void Restaurant::explainItemDetails()
{
    double itemCalories, itemPrice;
    string theItemName;
    for(unsigned int i = 0; i < menu.size(); i++)
    {
        cout << "Menu item" << i + 1 << " is: ";
        theItemName = menu[i].getItemName();    //We generally set non void assess functions/ regular functions
        itemCalories = menu[i].getCalories();   //equal to variables
        itemPrice = menu[i].getPrice();
        cout << theItemName << ", it has " << itemCalories << " calories and costs $" << itemPrice << endl;
    }
}

void Restaurant::addIngredients()
{
    string userIngredients;
    cout << "\nPlease add 3 new ingredients that we can put on our food: ";
    for(unsigned int i = 0; i < 3; i++)
    {
        cout << endl;
        cout << "Ingredients #" << i+1 << ": ";
        cin >> userIngredients;
        ingredients.push_back(userIngredients);

        cout << endl;
    }
    cout << "The available ingredients  ";
    for(unsigned int i = 0; i < ingredients.size(); i++)
    {
        cout << endl;
        cout << ingredients[i] << endl;
    }
}

