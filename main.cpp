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

    return 0;
}