#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"
using namespace std;
namespace ariel{};



class Character{

    private:

        string name;
        Point location;
        int alivePoints;

        bool PlayerIsInTeam;

        string type;
        

    public:

        Character();

        //Constructors
        Character(string name, Point& location, int alivePoints);
      //  Character(string name, Point location);

        virtual ~Character() = default;

        bool isAlive(); //check if character alive(if to charachter have more them 0 Alive Points)
        
        double distance(Character* other) const; //Gets a pointer to another character and returns the distance between the characters

        void hit(int damagePoints); //Subtracts the amount hit points from the character.

        // get functions
        string getName() ; // get the name of the Character
        Point getLocation() ; //get the location of the Character
        int getAlivePoints() const; // get the life Points of the Character

        //set functions
        void setLocation(const Point& otherLocation);
        void setAlivePoints(int addOrLessPoints);


        /*
        Prints the name of the character, the number of its hit points, and the location(position) of the point where the character is.
        If the character dies the number of hit points will not be printed, and the character's name will appear in parentheses - ( ). 
        Before the name will appear a letter indicating the type of character: N for ninja and C for morning.
        */
        string print(); 


        void inTeam();
        bool isTaken();

        void setType(string type);
        string getType();

        Character (Character&); // Copy Constructor.
        Character(Character&& ) noexcept; // Move Constructor.
        Character& operator = (const Character&); // Copy assignment operator.
        Character& operator = (Character&&) noexcept; // Move assignment operator.
        


};


#endif