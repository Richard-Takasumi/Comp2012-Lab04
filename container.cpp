#include "container.h"
#include <iostream>

void Container::addObject(Object *object)   //Task 1&3
{
    // sanity checks

    if (this->_num_object + 1 < MAX_OBJECT_NUM) {
        return;
    }

    if (object->getSize().x * object->getSize().y > this->getSize().x * this->getSize().y) {
        cout << "The object " << object->getName() << " is too large and cannot be added to " << this->getName() << endl;
        return;
    }

    _objects[this->_num_object++] = object;


}

void Container::display() const //Task 1
{
    std::cout << "\nContainer";
    this->displayBasic();
    std::cout <<"\n\t\t";
    std::cout << "#objects: " << this->_num_object << endl;
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
        if (_objects[i]) {
            delete _objects[i];
        }
    }

}