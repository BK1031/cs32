//
// Created by Bharat Kathi on 5/17/22.
//

#include "IceCreamItem.h"

IceCreamItem::IceCreamItem(std::string size) {
    this->size = size;
    if (size == "small") {
        price += 3.00;
    }
    else if (size == "medium") {
        price += 5.00;
    }
    else if (size == "large") {
        price += 6.50;
    }
}