/* 
 * This is the header file spherical.hpp. This file contains the defines and function 
 * prototypes for the spherical.cpp file.
 * 
 * File:   spherical.hpp
 * Author: Adam Claxton
 *
 * Created on October 7, 2020, 7:40 PM
 */

#ifndef SPHERICAL_HPP
#define SPHERICAL_HPP
#define M_PI 3.141592653589793238 // Defining PI to enough decimal places  

// creating struct to return the values of the spherical coordinates 
typedef struct { 
    double radius; // length to the sphere from the origin 
    double azimuth; // angle of the vector off the +x axis in the xy plane
    double inclination; // angle of the vector off the +z axis 
}SphericalCoords;

/*
 * Function Prototypes 
 * Defaults all set to origin values so that if a value is not passed the default is that angle or value was on the origin 
 */
double *sphericalToRectangular(double r = 0.0, double azimuth = 0.0, double inclination = (M_PI/2.0)); // returns array[x,y,z]
SphericalCoords rectangularToSpherical(double x = 0.0 , double y = 0.0 , double z = 0.0); //  returns struct containing radius, azimuth and inclination 

// inline function that computs radius. The code for this function goes in the header because it is treated as a macro
inline double getRadius(double x = 0.0, double y = 0.0, double z = 0.0){ 
    double radius = sqrt(x*x + y*y + z*z);
    
    return radius;    
}

#endif /* SPHERICAL_HPP */

