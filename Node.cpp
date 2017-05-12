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
        ids.insert(ids.end(), std::pair<std::string, std::shared_ptr<Node>>(id, n));
        //ids[id] = n;

    n.get()->parent   = this;
    n.get()->root     = this->root;

    children.push_back(n);
}

void Node::addChild(std::shared_ptr<Node> node, std::string const & id) {
    node->parent    = this;
    node->root      = this->root;

    children.push_back(std::move(node));
}

std::string Node::getName() {
    return name;
}

Node *Node::getParent() const {
    return parent;
}

Node * Node::getNodeById(std::string const &id) const {
    //return ids.find(id)->second.get(); // TODO: exception if not found

    for(std::pair<std::string, std::shared_ptr<Node>> node : ids) {
        std::cout << node.first << std::endl;
    }

    return nullptr;
}
