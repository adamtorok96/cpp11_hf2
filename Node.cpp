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

void Node::prettyPrint(size_t depth) {
    for(auto child = children.begin(); child != children.end(); child++) {
        std::cout << std::string(depth, '\t') << "<" << (*child)->name << ">" << std::endl;

        (*child)->prettyPrint(depth + 1);

        std::cout << std::string(depth, '\t') << "</" << (*child)->name << ">" << std::endl;
    }
}

void Node::addChild(Node * node) {
    children.push_back(std::shared_ptr<Node>{node});

    children.back().get()->parent = this;
}

void Node::addChild(std::shared_ptr<Node> node) {
    node->parent = this;

    children.push_back(std::move(node));
}

std::string Node::getName() {
    return name;
}

Node *Node::getParent() const {
    return parent;
}