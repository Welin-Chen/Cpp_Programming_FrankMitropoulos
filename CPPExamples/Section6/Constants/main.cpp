/**************
 * Pseudocode:
 *  Prompt the user to enter the number of rooms
 *  Display the number of rooms
 *  Display the price per rooms
 * 
 *  Display cost: (number of rooms*price per room)
 *  Display tax: (number of rooms*price per room*tax rate)
 *  Display total estimate: (number of rooms*price per room)+(number of rooms*price per room*tax rate)
 *  Display estimate expiration time
 * 
 * ***************/
 

#include <iostream>

using namespace std;

int main(){
    cout << "Hello, welcome to Welin's Carpet Cleaning Service" <<endl;
    cout << "\nHow many rooms would you like cleaned? ";
    
    int number_of_rooms {0};
    cin >> number_of_rooms;
    
    const double price_per_room {32.5};
    const double sales_tax {0.06};
    const int estimate_expiry {30};

    
    cout<<"\nEstimate for carpet cleaning service"<<endl;
    cout<<"Number of rooms: "<<number_of_rooms<<endl;
    cout<<"Price of room: $ "<<price_per_room<<endl;
    cout<<"Cost : $ "<<price_per_room*number_of_rooms<<endl;
    cout<<"Tax : $ "<<price_per_room*number_of_rooms*sales_tax<<endl;
    cout<<"================================"<<endl;
    cout<<"Total estimate : $ "<<(price_per_room*number_of_rooms) + (price_per_room*number_of_rooms*sales_tax)<<endl;
    cout<<"This estimate is valid for "<<estimate_expiry<<" days"<<endl;


    
    cout << endl;
    return 0;
}