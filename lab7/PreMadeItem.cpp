//
// Created by Bharat Kathi on 5/17/22.
//
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include "PreMadeItem.h"

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size), name(name) {
    price += 1.00;
}

PreMadeItem::~PreMadeItem() {}

double PreMadeItem::getPrice() {
    return price;
}

std::string PreMadeItem::composeItem() {
    std::string composed = "Pre-made Size: " + size + "\n";
    composed += "Pre-made Item: " + name + "\n";
    std::stringstream str;
    str << std::fixed << std::setprecision(2) << price;
    composed += "Price: $" + str.str() + "\n";
    return composed;
}