#pragma once
#include <iostream>
//maakt de I Container
class IContainer{
    public:
        virtual bool isEmpty() = 0;
        virtual bool isFull() = 0;
};