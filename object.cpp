#include <iostream>
#include "object.h"

const Pair Object::getSize() const
{
    return _size;
}

const Pair Object::getPosition() const  //Task 2
{
    int x_pos = _position.x;
    int y_pos = _position.y;
    if (this->_parent != nullptr) {
        x_pos += this->_parent->getPosition().x;
        y_pos += this->_parent->getPosition().y;
    }
    Pair position{x_pos, y_pos};
    return position;

}

const char* Object::getName() const
{
    return _name;
}

void Object::setSize(int x, int y)  //Task 3
{
    if (x > SCREEN_RESOLUTION.x || y > SCREEN_RESOLUTION.y) {
        cout << "Invalid size of " << this->getName() << endl;
    }

}

void Object::setPosition(int x, int y)  //Task 3
{


}

void Object::setName(const char*name)
{
    for(int i = 0;i<MAX_NAME_LENGTH; i++)
    {
        _name[i] = name[i];
        if(name[i]=='\0') break;
    }
}

void Object::setParent(Object* parent)
{
    _parent = parent;
}

void Object::displayBasic() const
{
    cout << "\n\tName: ["<< getName()<<"]"; 
    cout <<"\n\tPosition: ("<< getPosition().x << ", "<< getPosition().y<<")";
    cout <<"\n\tSize: (" <<  getSize().x << ", "<< getSize().y<<") ";
}

Object::Object() : _size{0,0}, _position{0,0}, _parent{nullptr}
{
    _name = new char[MAX_NAME_LENGTH];
    _name[0]='\0';
}

Object::~Object()
{
    if (_name != nullptr) 
        delete [] _name;
}