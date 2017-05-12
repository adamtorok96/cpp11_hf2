//
// Created by edems on 2017.05.10..
//

#include <iostream>
#include "Node.h"

void Node::print() {
    for(auto child = children.begin(); child != children.end(); child++) {
        std::cout << "<" << (*child)->name << ">";

        (*child)->print();

        std::cout << "</" << (*child)->name << ">";
    }
}

void Node::addChild(std::unique_ptr<Node> node) {
    node->parent = this;

    children.push_back(std::move(node));
}
