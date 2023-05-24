#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel{};

class Ninja : public Character{

    private:

        int speed;

    public:

        //constructor
        Ninja(string name, Point location, int alivePoints, int speed);

        //get function
        int getSpeed() const;


        /*
        function receives a pointer to enemy and towards to the enemy.
        The ninja moves a distance equal to its speed.
        */
        void move(Character* enemy);

        /*
        function Receives a pointer to the enemy.
        If the ninja is alive and the enemy is less than 1 meter away, the ninja will do 40 damage to the enemy. 
        Otherwise, no damage will be done to the enemy.
        */
        void slash(Character* enemy);

        

};


#endif