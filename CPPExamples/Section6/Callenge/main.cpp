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
    cout << "\nHow many small rooms would you like cleaned? ";
    int number_of_small_rooms {0};
    cin >> number_of_small_rooms;
    
    cout << "How many large rooms would you like cleaned? ";
    int number_of_large_rooms {0};
    cin >> number_of_large_rooms;
    
    const double price_per_small_room {25};
    const double price_per_large_room {35};
    const double sales_tax {0.06};
    const int estimate_expiry {30};
    
    double cost_small_room {0};
    double cost_large_room {0};
    double cost {0};
    cost_small_room=price_per_small_room*number_of_small_rooms;
    cost_large_room=price_per_large_room*number_of_large_rooms;
    cost=cost_small_room+cost_large_room;
    
    cout<<"\nEstimate for carpet cleaning service"<<endl;
    cout<<"Number of small rooms: "<<number_of_small_rooms<<endl;
    cout<<"Number of large rooms: "<<number_of_large_rooms<<endl;

    cout<<"Price of small room: $ "<<price_per_small_room<<endl;
    cout<<"Price of large room: $ "<<price_per_large_room<<endl;

    cout<<"Cost : $ "<<cost<<endl;
    cout<<"Tax : $ "<<cost*sales_tax<<endl;
    cout<<"================================"<<endl;
    cout<<"Total estimate : $ "<<cost*(1+sales_tax)<<endl;
    cout<<"This estimate is valid for "<<estimate_expiry<<" days"<<endl;


    
    cout << endl;
    return 0;
}