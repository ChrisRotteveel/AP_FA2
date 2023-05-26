#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Empolyee.hpp"
#include"Shelf.hpp"
//hpp for warehouse file
class Warehouse
{
public:
    std::vector<Employee> Employees;
    std::vector<Shelf> Shelves;
    Warehouse(std::string itemName, int itemCount);
    bool pickItems(std::string itemName, int itemCount);
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrange(Shelf& shelf);
};
