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

void Node::addChild(Node * node, std::string const & id) {
    std::shared_ptr<Node> n{node};

    if( !id.empty() )
        this->root->ids[id] = n;

    n.get()->parent   = shared_from_this();
    n.get()->root     = this->root;

    children.push_back(n);
}

std::string Node::getName() {
    return name;
}

std::weak_ptr<Node> Node::getParent() const {
    return parent;
}

Node * Node::getNodeById(std::string const &id) const {
    return ids.at(id).get();
}
