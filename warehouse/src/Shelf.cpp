#include "include\Shelf.hpp"
Shelf::Shelf(){
    pallets = { Pallet(), Pallet(), Pallet(), Pallet()};
}

bool Shelf::swapPallet(int slot, int slot2){
    //swapt de pallets maar alleen als de slots kloppen.
    if(slot > 0 && slot < 5 && slot2 > 0 && slot2 < 5 && slot != slot2){
        int s = slot;
        slot = slot2;
        slot2 = s;
        return true;
    }
    return false;
}