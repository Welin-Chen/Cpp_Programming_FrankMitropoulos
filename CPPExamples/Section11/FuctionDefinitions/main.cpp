#include <iostream>
#include <cmath>

using namespace std;

double pi{3.14159};
void area_circle();
void volume_cylinder();

int main()
{
    area_circle();
    volume_cylinder();

    cout << endl;
    return 0;
}

double cal_area_circle(double radius)
{
    return pi * pow(radius, 2);
}
double cal_volume_cylinder(double radius, double height)
{
    return cal_area_circle(radius) * height;
}
void area_circle()
{
    double radius{};
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "The area of a circle with radius " << radius << " is " << cal_area_circle(radius) << endl;
}

void volume_cylinder()
{
    double radius{};
    double height{};
    cout << "\nEnter the radius of the volume_cylinder: ";
    cin >> radius;
    cout << "Enter the height of the volume_cylinder: ";
    cin >> height;
    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << cal_volume_cylinder(radius, height) << endl;
}