#ifndef CPP11_HF2_NODE_H
#define CPP11_HF2_NODE_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>

class Node : public std::enable_shared_from_this<Node> {
    std::string name;

    std::weak_ptr<Node> root, parent;

    std::set<std::shared_ptr<Node>> children;
    std::map<std::string, std::shared_ptr<Node>> ids;

public:
    Node() {}
    Node(std::string const & name) : name{name} {}

    void print();
    void prettyPrint(size_t depth = 0);

    void addChild(Node * node, std::string const & id);

    std::string getName();

    std::shared_ptr<Node> getNodeById(std::string const & id);
    std::shared_ptr<Node> getNodeById(std::string const & id) const;
    std::weak_ptr<Node> getParent() const;

    std::set<std::shared_ptr<Node>> getChildren() const;

    std::shared_ptr<Node> nextSibling();
    std::shared_ptr<Node> previousSibling();
};


#endif //CPP11_HF2_NODE_H
