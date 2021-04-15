/*
 * This is the source file spherical.cpp for comp lab 03. This file contains 
 * functions for converting from spherical coordinates to rectangular coordinates 
 * and visa versa. 
 * 
 * Author: Adam Claxton 
 * Date: OCT 7th 2020
 */
// include required files for this program 
#include <cmath>
#include "spherical.hpp" // header file with defines and function prototypes 

using namespace std; // using standard name space 

// converts from spherical to rectangular, input radius, azimuth and inclination and returns array[x,y,z]
double *sphericalToRectangular( double r, double azimuth, double inclination){
    double *recCoords = new double[3]; // creates and array of 3 doubles to store coords x,y,z
    
    recCoords[2] = r*cos(inclination); // calculates z component and stores it at the 3rd spot in the array 
    recCoords[1] = r*sin(inclination)*sin(azimuth); // calculates y component and stores it at the 2rd spot in the array 
    recCoords[0] = r*sin(inclination)*cos(azimuth); // calculates x component and stores it at the 1rd spot in the array 
    
    return recCoords; // returns the array[x,y,z] 
}

// converts from rectangular to spherical coordinates, input x,y,z and returns struct of radius, inclination and azimuth
SphericalCoords rectangularToSpherical(double x, double y, double z){
    SphericalCoords Coords; // create new instance of the SphericalCoords Struct  
    double xy = sqrt(x*x + y*y); // find the length of the vector in the xy plane 
    
    Coords.radius = getRadius(x, y, z); // uses the inline function getRadius to determine the radius of the sphere 
    Coords.azimuth = atan2(y,x); // find the angle azimuth, use tan2 because it has a range from -pi to pi(same as azimuth) 
    Coords.inclination = atan2(xy,z);// find the angle inclination, use tan2 because it has a range from -pi to pi(same as inclination)
    
    return Coords; // returns the struct with all the Spherical coordinates 
}

