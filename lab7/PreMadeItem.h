//
// Created by Bharat Kathi on 5/17/22.
//

#ifndef LAB7_PREMADEITEM_H
#define LAB7_PREMADEITEM_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "IceCreamItem.h"

class PreMadeItem : public IceCreamItem {
public:
    PreMadeItem(std::string name, std::string size);
    virtual ~PreMadeItem();
    double getPrice();
    std::string composeItem();
protected:
    std::string name = "";
};


#endif //LAB7_PREMADEITEM_H
