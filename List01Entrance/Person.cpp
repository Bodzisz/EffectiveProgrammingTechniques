//
// Created by bodzisz on 21/10/2021.
//

#include "Person.h"

Person::Person()
{
    name = "";
    friends = new Person*[256];
    friendsLength = 256;
    numberOfFriends = 0;
}

Person::Person(std::string name, int friendsLength)
{
    this->name = name;
    this->friends = new Person*[friendsLength];
    this->friendsLength = friendsLength;
    this->numberOfFriends = 0;
}

void Person::introduce(Person *other)
{
    addToFriends(this, other);
    addToFriends(other, this);
}

void Person::addToFriends(Person *person1, Person *person2)
{
    if(person1->numberOfFriends  < person1->friendsLength)
    {
        person1->friends[person1->numberOfFriends] = person2;
    }
    else
    {
        person1->friends[0] = person2;
    }
    person1->numberOfFriends++;
}

Person::~Person()
{
//    for(int i = 0; i < numberOfFriends; i++)
//    {
//        bool found = false;
//        for(int j = 0; j < (*friends)[i].numberOfFriends; j++)
//        {
//            if(found)
//            {
//                (*friends[i]).friends[j-1] = (*friends[i]).friends[j];
//            }
//            if((*friends)[i].name == (*friends[i]).friends[j]->name)
//            {
//                found = true;
//                (*friends)[i].numberOfFriends--;
//            }
//        }
//    }
//
    for(int i = 0; i < numberOfFriends; i++)
    {
        (*friends)[i].numberOfFriends--;
    }
    delete [] friends;
}

Person::Person(Person &other)
{
    name = other.name;
    friends = new Person*[other.friendsLength];
    friendsLength = other.friendsLength;
    numberOfFriends = 0;
}

std::string Person::getName()
{
    return name;
}

Person *Person::getFriends()
{
    return *friends;
}

int Person::getFriendsLength()
{
    return friendsLength;
}

int Person::getNumberOfFriends()
{
    return numberOfFriends;
}




