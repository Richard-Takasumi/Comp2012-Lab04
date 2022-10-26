#include "container.h"
#include <iostream>

void Container::addObject(Object *object)   //Task 1&3
{
    // sanity checks

    if (this->_num_object + 1 > MAX_OBJECT_NUM) {
        return;
    }

    if (object->getSize().x + object->getPosition().x > this->getSize().x + this->getPosition().x
    ||  object->getSize().y + object->getPosition().y > this->getSize().y + this->getPosition().y) {
        cout << "The object " << object->getName() << " is too large and cannot be added to " << this->getName() << endl;
        return;
    }

    _objects[this->_num_object] = object;
    this->_num_object++;
    object->setParent(this);
}

void Container::display() const //Task 1
{
    std::cout << "\nContainer";
    this->displayBasic();
    std::cout <<"\n\t\t";
    if (this->_num_object > 0) {
        std::cout << "#objects: " << this->_num_object << endl;
    }

    for (int i = 0; i < this->_num_object; i++) {
        this->_objects[i]->display();   
    }
}

Container::Container() 
{
    for (int i = 0; i < MAX_OBJECT_NUM; i++)
        _objects[i] = nullptr;

    _num_object = 0;
}

Container::~Container()  //Task 1
{
    cout << "\nDestructing Container " << this->getName();
    for (int i = 0; i < this->_num_object; i++) {
        delete _objects[i];
    }

}