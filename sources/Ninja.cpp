#include <iostream>
#include "Ninja.hpp"


Ninja :: Ninja (string name, Point location, int alivePoints, int speed): Character(name, location, alivePoints){
    this ->speed  = speed;
    this->setType("Ninja");

}

int Ninja :: getSpeed() const{
    return this ->speed;
}

/*
C_x = A_x + (n * (B_x - A_x)) / ||AB||
C_y = A_y + (n * (B_y - A_y)) / ||AB||

*/
void Ninja :: move(Character* enemy){

    this->setLocation( this->getLocation().moveTowards(this->getLocation() , enemy->getLocation() , this->speed));

}

void Ninja :: slash(Character* enemy)
{

    if (this == enemy){
        throw std::runtime_error ("You can not slash yourself");
    }
    if (this ->isAlive() == false){
        throw std::runtime_error ("You Are Dead, dead Ninja can not slash");
    }
    if (enemy ->isAlive() == false){
        throw std::runtime_error ("Enemy is Dead already, you can not slash at dead enemy");
    }
    
    if (this->getLocation().distance(enemy->getLocation()) <= 1){
        enemy->hit(40);
    }


}

