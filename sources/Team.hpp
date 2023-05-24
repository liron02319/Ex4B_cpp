#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>

#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel{};

class Team{

   private:

        Character* leader;
        vector <Character*> players;

    public:

  

        

        //constructor
        Team(Character* leader);
        Team();


        //distructor
        virtual ~Team(){
        for(size_t i=0 ; i<players.size() ;i++){
            delete players.at(i);
            }
        }

        //requested function 

        void add(Character* newPlayer); //Receives a pointer for a cowboy or ninja, and adds it to the team

        /*
        First check if the leader of the attacking Team is alive.
        Otherwise, a new leader must be chosen, which is the closest living character in terms of location to the dead leader.
        Then the group will choose a victim from the group of enemies
        The victim is the living enemy group member standing closest to the leader of the attacking group.
        All living members of the attacking Team will attack the chosen victim. Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons.
        Ninjas that are less than 1 meter away from the victim will kill the victim, and ninjas that are further away will advance towards the victim.
        At each stage, if the victim is dead a new victim will be chosen which will be, again, 
        the victim is the closest living enemy character to the leader of the attacking team.
        If there are no living members in the attacking group or the enemy group the attack will end.
        */

        void attack(Team* other); //receives a pointer to the enemy team for attack

        int stillAlive(); //Returns the count players that still Alive at Team

        void print(); //Goes through all the characters in the group and prints their details


      void addToMembers(Character* newChar);


        Character* getLeader();

        void setLeader(Character *leader);

        std::vector <Character*> getFighters() const{
            return players;
        }

        Character* findClosestAliveFighter(const Team &team, const Character *leader) const;


        Team (Team&) = delete; 
        Team (Team&&) noexcept = delete;
        Team& operator = (const Team&) = delete; 
        Team& operator = (Team&&) noexcept = delete;
    


};


#endif