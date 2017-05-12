#include <iostream>
#include <fstream>
#include "Node.h"
#include "HTMLParser.h"


int main() {
    std::ifstream is("html.html");

    std::unique_ptr<Node> root{HTMLParser::parse(is)};

    is.close();

    root->print();

    std::cout << std::endl;

    root->prettyPrint();

    //root->getNodeById("myUl");
    //root->getNodeById("myBody")->print();

    root->getNodeById("myUl")->print();

    return 0;
}