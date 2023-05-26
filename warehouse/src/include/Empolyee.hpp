#pragma once
#include<string>
#include"Warehouse.hpp"
//maak hpp file van employee
class Employee{
    private:
        const std::string name;
        bool busy;
        bool forkliftCertificate;
    public:
        Employee(std::string name, bool forkliftCertificate);
        std::string getName();
        bool getBusy();
        void setBusy(bool busy);
        bool getForkliftCertificate();
        void setForkliftCertificate(bool forkliftcertificate);
};