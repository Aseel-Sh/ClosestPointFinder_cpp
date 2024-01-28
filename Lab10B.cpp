#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point {
    int x, y, z;
    double dist = 0;
};



int main() {
 
    const int maxPoints = 100; 

    Point points[maxPoints];
    int numPoints;

    ifstream file("data.dat");

    if (!file.is_open()) {
        cerr << "Error opening file: data.dat" << endl;
        return 1;
    }

    numPoints = 0;
    while (file >> points[numPoints].x >> points[numPoints].y >> points[numPoints].z) {
        numPoints++;
    }

    file.close(); 

    Point userPoint;
    cout << "Enter a three-dimensional point (x y z): ";
    cin >> userPoint.x >> userPoint.y >> userPoint.z;

    Point closestPoint = points[0];
    closestPoint.dist = sqrt(pow(userPoint.x - points[0].x, 2) +
                         pow(userPoint.y - points[0].y, 2) +
                         pow(userPoint.z - points[0].z, 2));


for (int i = 0; i < numPoints; i++) {
    double distance = sqrt(pow(userPoint.x - points[i].x, 2) +
                           pow(userPoint.y - points[i].y, 2) +
                           pow(userPoint.z - points[i].z, 2));


    if (distance < closestPoint.dist) {
        closestPoint = points[i];
        closestPoint.dist = distance; 
    }
}



    cout << "Closest point to the entered point: (" << closestPoint.x << ", "
         << closestPoint.y << ", " << closestPoint.z << ")" << endl;
    cout << "Distance: " << closestPoint.dist << endl;

    return 0;
}