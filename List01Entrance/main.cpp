#include <iostream>
#include "Person.h"

int main()
{

    // statycznie
    Person person("123", 20);
    std::cout << person.getName() << " " << person.getFriendsLength() << std::endl;

    // dynamicznie
    Person *person1 = new Person("person1", 10);
    Person *person2 = new Person("person2", 30);
    std::cout << person1->getName() << " " << person1->getFriendsLength() << std::endl;

    std::cout << person1->getNumberOfFriends() << std::endl;
    std::cout << person2->getNumberOfFriends() << std::endl;

    person1->introduce(person2);

    std::cout << person1->getNumberOfFriends() << std::endl;
    std::cout << person2->getNumberOfFriends() << std::endl;

    Person *person3 = new Person(*person1);
    std::cout << person3->getName() << " " << person3->getFriendsLength() << " " << person3->getNumberOfFriends() << std::endl;

    delete person1;

    Person *person4 = new Person("person4", 30);
    person2->introduce(person4);
    for(int i = 0; i < person2->getNumberOfFriends(); i++)
    {
        std::cout << person2->getFriends()[i].getName() << " ";
    }
    std::cout << "\n";


    delete person2;
    delete person3;
    delete person4;

    return 0;
}
