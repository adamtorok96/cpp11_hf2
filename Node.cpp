#include <iostream>
#include <algorithm>
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

    if( !this->root.lock() )
        this->root = shared_from_this();

    if( !id.empty() ) {
        this->root.lock()->ids[id] = n;
    }

    n.get()->parent   = shared_from_this();
    n.get()->root     = this->root;

    children.insert(n);
}

std::string Node::getName() {
    return name;
}

std::weak_ptr<Node> Node::getParent() const {
    return parent;
}

std::shared_ptr<Node> Node::getNodeById(std::string const &id) const {
    return ids.at(id);
}

std::set<std::shared_ptr<Node>> Node::getChildren() const {
    return children;
}

std::shared_ptr<Node> Node::nextSibling() {
    std::shared_ptr<Node> parent = this->parent.lock();

    if( !parent || parent->children.size() == 0 )
        return nullptr;

    auto it = ++parent->children.find(shared_from_this());

    return it == parent->children.end() ? nullptr : *it;
}

std::shared_ptr<Node> Node::previousSibling() {
    std::shared_ptr<Node> parent = this->parent.lock();

    if( !parent || parent->children.size() == 0 )
        return nullptr;

    auto it = parent->children.find(shared_from_this());

    return it == parent->children.begin() ? nullptr : *(--it);
}
