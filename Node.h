#ifndef CPP11_HF2_NODE_H
#define CPP11_HF2_NODE_H

#include <string>
#include <vector>
#include <memory>
#include <map>

class Node : public std::enable_shared_from_this<Node> {
    std::string name;

    Node * root;

    std::weak_ptr<Node> parent;

    //std::vector<std::shared_ptr<Node>> children;
    std::vector<std::shared_ptr<Node>> children;

    std::map<std::string, std::shared_ptr<Node>> ids;

public:
    Node() : root{this} {}
    Node(std::string const & name) : name{name} {}

    void print();
    void prettyPrint(size_t depth = 0);

    void addChild(Node * node, std::string const & id);

    std::string getName();

    Node * getNodeById(std::string const & id) const;
    std::weak_ptr<Node> getParent() const;
};


#endif //CPP11_HF2_NODE_H
