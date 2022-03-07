// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void ruler()
{
    std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890" << endl
              << endl;
}

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    ruler();
    // Unformatted display so you can see how to access the vector elements

    // cout << title_len << endl;
    // 70/2+(29-1)/2=49
    // 70/4=17*3+19
    const int total_width{70};
    const int field1_width{20}; //country
    const int field2_width{20}; //city
    const int field3_width{15}; //population
    const int field4_width{15}; //cost

    int title_len = tours.title.length();
    std::cout << setw((total_width - title_len) / 2) << "" << tours.title;
    cout << endl
         << endl;

    std::cout << setw(field1_width) << left << "Country"
              << setw(field2_width) << left << "City"
              << setw(field3_width) << right << "Population"
              << setw(field4_width) << right << "Price"
              << std::endl;

    cout << setw(total_width);
    cout << setfill('-') << "";
    cout << endl;

    cout << setfill(' ');
    cout << fixed << setprecision(2);

    for (auto country : tours.countries)
    { // loop through the countries
        for (size_t i = 0; i < country.cities.size(); i++)
        { // loop through the cities for each country
            cout << setw(field1_width) << left << ((i == 0) ? country.name : "")
                 << setw(field2_width) << left << country.cities.at(i).name
                 << setw(field3_width) << right << country.cities.at(i).population
                 << setw(field4_width) << right << country.cities.at(i).cost
                 << std::endl;
        }
    }

    std::cout << std::endl
              << std::endl;
    return 0;
}