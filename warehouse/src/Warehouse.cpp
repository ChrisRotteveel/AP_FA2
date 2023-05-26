#pragma once
#include"include\Warehouse.hpp"
Warehouse::Warehouse(std::string itemName, int itemCount){
    std::string itemName = "";
    int itemCount = 0;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int remainingItemCount = itemCount;
    //kijkt naar alle shelves
    for (Shelf& shelf : Shelves) {
        // zit het item op de pallets
        if (!shelf.isEmpty() && shelf.pallets[0].getItemName() == itemName) {
            int availableItems = shelf.pallets[0].getItemCount();
            int itemsToPick = std::min(remainingItemCount, availableItems);
            // zitten er genoeg items op de pallets
            for (int i = 0; i < itemsToPick; i++) {
                if (!shelf.pallets[0].takeOne()) {
                    return false;
                }
            }

            remainingItemCount -= itemsToPick;
            // als het gelukt is om alle items te pakken dan returnd hij true anders false
            if (remainingItemCount == 0) {
                return true;
            }
        }
    }
    return false;
}

void Warehouse::addEmployee(Employee employee) {
    //voeg employee toe in de lijst
    Employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    //voeg shelf toe aan de lijst
    Shelves.push_back(shelf);
}

bool Warehouse::rearrange(Shelf& shelf) {
    Employee* availableEmployee = nullptr;
    //kijkt of er een employee is met een forklift diploma
    for (Employee& employee : Employees) {
        if (!employee.getBusy() && employee.getForkliftCertificate()) {
            availableEmployee = &employee;
            break;
        }
    }
    // is er geen forklift diploma werknemer of de shelf is niet vol dan return false
    if (availableEmployee == nullptr || !shelf.isFull()) {
        return false;
    }

    for (int i = 0; i < shelf.pallets.size() - 1; i++) {
        for (int j = 0; j < shelf.pallets.size() - i - 1; j++) {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount()) {
                // vewissel pallets als de item count niet geordend is
                if (!shelf.swapPallet(j, j + 1)) {
                    //kan het niet return false
                    return false;
                }
            }
        }
    }
    //is alles gelukt return dan true
    return true;
}
