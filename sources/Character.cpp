#include <iostream>
#include <cmath>
#include "Character.hpp"

using namespace std;

Character :: Character (){
}

Character :: Character(string name, Point& location, int alivePoints): location(location){
    this -> name = name;
    this ->alivePoints = alivePoints;
    this ->PlayerIsInTeam = false;
    this -> type = "character";
}

//Character :: Character(string name, Point location): location(location){
//    this -> name = name;
//}

bool Character :: isAlive(){
    if (this ->alivePoints > 0){
        return true;
    }
    return false;
}

double Character :: distance(Character* other) const{

    return this->location.distance(other->getLocation());
}

void Character :: hit(int damagePoints){ 

    if (damagePoints < 0 ){
        throw std::invalid_argument ("hit (damagePoints) Can't be a negative number");
    }
    this ->alivePoints = alivePoints-damagePoints;
}

string Character::getName(){
    return this ->name;
}

Point Character :: getLocation(){
    return this ->location;
}


int Character :: getAlivePoints() const {
    return this ->alivePoints;
}
void Character :: setLocation(const Point &otherLocation){
    this ->location = otherLocation;
}

void Character :: setAlivePoints(int addOrLessPoints){
    this ->alivePoints = alivePoints+addOrLessPoints;
    cout << this->alivePoints << endl;
}

string Character :: print()
{
    string alive_Points =  to_string(this -> alivePoints);
    string detailsCharacter = this -> name +  " is standing at Point " + (this ->location.print()) + " and have " + alive_Points + " Alives Points.";
    return detailsCharacter;

}


void Character :: inTeam(){
    this ->PlayerIsInTeam = true;
}

bool Character :: isTaken(){
    return PlayerIsInTeam;
}


void Character :: setType(string type){
    this ->type = type;
}

string Character :: getType(){
    return this-> type;
}
