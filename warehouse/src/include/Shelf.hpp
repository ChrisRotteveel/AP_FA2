#pragma once
#include<iostream>
#include<string>
#include<array>
#include"Pallet.hpp"
#include"IContainer.hpp"

//shelf.hpp file
class Shelf: public IContainer{
    public:
        std::array<Pallet, 4> pallets;
        Shelf();
        bool swapPallet(int slot, int slot2);
        bool isEmpty() override;
        bool isFull() override;
};