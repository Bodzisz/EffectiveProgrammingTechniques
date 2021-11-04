//
// Created by bodzisz on 21/10/2021.
//

#ifndef LIST01ENTRANCE_PERSON_H
#define LIST01ENTRANCE_PERSON_H

#include <string>


class Person {
private:
    std::string name;
    Person **friends;
    int friendsLength;
    int numberOfFriends;

public:
    Person();
    Person(std::string name, int friendsLength);
    void introduce(Person *other);
    void addToFriends(Person *person1, Person *person2);
    ~Person();
    Person(Person &other);

    std::string getName();
    Person *getFriends();
    int getFriendsLength();
    int getNumberOfFriends();

};


#endif //LIST01ENTRANCE_PERSON_H
