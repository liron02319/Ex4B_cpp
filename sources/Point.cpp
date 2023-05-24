#include <iostream>
#include <cmath>
#include "Point.hpp"

using namespace std;


Point :: Point(){
    
}
// "outline" constructor implementation:
Point::Point(double p_x, double p_y){
    this -> x = p_x;
    this -> y = p_y;
}

double Point::getX() const{
    return this -> x;
}

double Point::getY() const{
    return this -> y;
}

double Point::distance(Point other) const{ // sqrt( (x1-x2)^2 + (y1-y2)^2 )
    return (std::sqrt (std::pow( this ->x - other.getX(), 2) + std :: pow(this ->y - other.getY(),2) ) );
}

string Point::print(){
    string s = "(" + to_string(this ->x) + " , " + to_string(this ->y) + " )"  ;
    return s;    
}


Point Point :: moveTowards(Point source, Point destination, double distance){

    if (distance < 0){
        throw std::invalid_argument("Distance must be positive ( > 0)");
    }

    if (source.distance(destination) <= distance){
        return destination;
    }


    double delta_x = destination.x - source.x;
    double delta_y = destination.y - source.y;
    double totalDistance = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));

    double closestPointX = source.x + (delta_x * distance / totalDistance);
    double closestPointY = source.y + (delta_y * distance / totalDistance);


    return Point(closestPointX, closestPointY);
}

