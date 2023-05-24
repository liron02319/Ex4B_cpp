#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel{};

class Cowboy : public Character{

    private:

       int bulletsInPistol;

    public:
        //constructor
        Cowboy(string name, Point location);
        
        /*
        function receives a pointer to the enemy.
        If the Cowboy is not dead and has bullets left in pistol, 
        The Cowboy shoots the enemy, subtracting 10 hit points from the enemy - and losing 1 bullet. 
        Otherwise, no damage will be done to the enemy.
        */
        void shoot(Character* enemy);

        bool hasboolets(); // checks if there are bullets left in the Pistol

        void reload(); // adds 6 bullets to Pistol

        int getBulletsInPistol();
        

};


#endif