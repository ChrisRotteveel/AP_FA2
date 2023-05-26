#include "include\Pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}

Pallet::Pallet() {
    this->itemName = "";
    this->itemCapacity = 0;
    this->itemCount = 0;
}

std::string Pallet::getItemName() {
    return itemName;
}

int Pallet::getItemCount() {
    return itemCount;
}

int Pallet::getRemainingSpace() {
    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    //kijkt of de pallet leeg is als hij niet leeg is returnt false anders true
    if (itemCount == 0) {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    }
    return false;
}

bool Pallet::takeOne() {
    //als itemCount groter dan 0 is dan haalt hij er één van de pallet af
    if (itemCount > 0) {
        itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    //als de itemCount even groot is als de itemCapacity dan gaat er één van de pallet bij.
    if (itemCount < itemCapacity) {
        itemCount++;
        return true;
    }
    return false;
}