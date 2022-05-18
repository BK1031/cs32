//
// Created by Bharat Kathi on 5/17/22.
//

#ifndef LAB7_CUSTOMITEM_H
#define LAB7_CUSTOMITEM_H

#include <map>
#include "IceCreamItem.h"

class CustomItem : public IceCreamItem {
public:
    CustomItem(std::string size);
    virtual ~CustomItem();
    double getPrice();
    void addTopping(std::string topping);
    std::string composeItem();
protected:
    //map
    std::map<std::string, int> custom;
};


#endif //LAB7_CUSTOMITEM_H
