#ifndef CPP11_HF2_NODE_H
#define CPP11_HF2_NODE_H

#include <string>
#include <vector>
#include <memory>
#include <map>

class Node {
    std::string name;

    Node * root, * parent;

    std::vector<std::shared_ptr<Node>> children;
    std::map<std::string, std::shared_ptr<Node>> ids;

public:
    Node() : root{this}, parent{nullptr} {}
    Node(std::string const & name) : name{name}, parent{nullptr} {}

    void print();
    void prettyPrint(size_t depth = 0);

    void addChild(Node * node, std::string const & id);
    void addChild(std::shared_ptr<Node> node, std::string const & id);

    Node * getNodeById(std::string const & id) const;

    std::string getName();
    Node * getParent() const;
};


#endif //CPP11_HF2_NODE_H
