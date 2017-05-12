//
// Created by edems on 2017.05.10..
//

#ifndef CPP11_HF2_NODE_H
#define CPP11_HF2_NODE_H

#include <string>
#include <vector>
#include <memory>

class Node {
    std::string name;
    Node * parent;
    std::vector<std::unique_ptr<Node>> children;

protected:


public:
    Node() : parent(nullptr) {}
    Node(const std::string & name) : name{name}, parent(nullptr) {}

    void print();
    void addChild(std::unique_ptr<Node> node);
};


#endif //CPP11_HF2_NODE_H
