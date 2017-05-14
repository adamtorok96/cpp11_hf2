#include <iostream>
#include <fstream>
#include "Node.h"
#include "HTMLParser.h"


int main() {
    std::ifstream is("html.html");

    std::shared_ptr<Node> root{HTMLParser::parse(is)};

    is.close();

    root->print();

    std::cout << std::endl;

    root->prettyPrint();

    std::shared_ptr<Node> ul;

    try {
        ul = root->getNodeById("mylist");
    } catch (std::out_of_range const & exception) {
        std::cout << "mylist not found: " << exception.what();

        return 1;
    }

    ul->print();

    std::cout << std::endl;

    std::shared_ptr<Node> next_p = ul->nextSibling();

    if( !next_p ) {
        std::cout << "no next sibling element" << std::endl;
        return 1;
    }

    std::cout << next_p->getName() << std::endl;

    std::shared_ptr<Node> prev_p = next_p->previousSibling()->previousSibling();

    if( !prev_p ) {
        std::cout << "no previous sibling element" << std::endl;
        return 1;
    }

    std::cout << prev_p->getName() << std::endl;

    std::shared_ptr<Node> prev_not_found = prev_p->previousSibling();

    if( !prev_not_found ) {
        std::cout << "no previous sibling element, OK!" << std::endl;
    } else {
        std::cout << "found: " << prev_not_found->getName() << std::endl;
    }

    return 0;
}