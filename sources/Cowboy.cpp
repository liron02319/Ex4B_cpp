#include <iostream>
#include "Cowboy.hpp"

Cowboy :: Cowboy(string name, Point location) : Character(name, location,110){
    this ->bulletsInPistol = 6;
    this->setType("Cowboy");
}

void Cowboy :: shoot(Character* enemy){
   
    if (this == enemy){
        throw std::runtime_error ("You can not shot yourself ");
    }
    if (this ->isAlive() == false){
        throw std::runtime_error ("You Are Dead, dead cowboy can not shoot");
    }
    if (enemy ->isAlive() == false){
        throw std::runtime_error ("Enemy is Dead already, you can not shot at dead enemy");
    }
    if (this ->hasboolets() == false){
        return;
    }

    enemy->hit(10); //damage to enemy 10 points

    this->bulletsInPistol=bulletsInPistol-1; //shot one bullet
   
}

bool Cowboy :: hasboolets(){

    if (bulletsInPistol > 0){
        return true;}

    return false;
}

void Cowboy :: reload()
{
    if (this->isAlive() == false){
        throw std :: runtime_error ("This player Cowboy is dead");
    }
    this ->bulletsInPistol = 6;
} 

int Cowboy :: getBulletsInPistol(){
    return this->bulletsInPistol;
}