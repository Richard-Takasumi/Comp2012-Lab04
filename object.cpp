#include <iostream>
#include "object.h"

const Pair Object::getSize() const
{
    return _size;
}

const Pair Object::getPosition() const  //Task 2
{
    int x_pos = this->_position.x;
    int y_pos = this->_position.y;

    if (this->_parent != nullptr) {
        Pair temp_pair = this->_parent->getPosition(); 
        // cout << "parent of: " << this->_parent->getName() << "position being added to: " << this->getName() << endl;
        x_pos += temp_pair.x;
        y_pos += temp_pair.y;
    }
    Pair position{x_pos, y_pos};
    return position;

}

// (1000, 1000)
// (100, 100) => (1100, 1100)



const char* Object::getName() const
{
    return _name;
}

void Object::setSize(int x, int y)  //Task 3
{
    
    if (x  > SCREEN_RESOLUTION.x || y  > SCREEN_RESOLUTION.y) {
        // cout << this->getName() << " has a size of: " << x + this->getPosition().x << endl;
        cout << "Invalid size of " << this->getName() << endl;
        return;
    }
    
    if (x  < 0 || y  < 0) {
        // cout << this->getName() << " has a size of: " << x + this->getPosition().x << endl;
        cout << "Invalid size of " << this->getName() << endl;
        return;
    }

    _size.x = x;
    _size.y = y;
    return;

}

void Object::setPosition(int x, int y)  //Task 3
{
    if (x < 0 || y < 0 ) {
        cout << "Invalid position of " << this->getName() << endl;
        return;
    }
    // cout << "original of: " << this->getName() << " x: " << _position.x << " y: " << _position.y << endl;

    // Pair Offset = this->getPosition();
    // cout << "offset of: " << this->getName() << " x: " << Offset.x << " y: " << Offset.y << endl;
    _position.x =  x;
    _position.y =  y;
    return;
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