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

    //root->getNodeById("myUl");
    //root->getNodeById("myBody")->print();

    root->getNodeById("myUl")->print();

    std::shared_ptr<Node> firstElementOfBody = (*root->getNodeById("myBody")->getChildren().begin());

    firstElementOfBody->nextSibling()->print();

    std::cout << firstElementOfBody->nextSibling() << std::endl;

    std::cout << std::endl;

    firstElementOfBody->nextSibling()->nextSibling()->print();

    std::cout << std::endl;

    std::cout << firstElementOfBody->nextSibling()->nextSibling()->previousSibling()->getName() << std::endl;
    firstElementOfBody->nextSibling()->nextSibling()->previousSibling()->print();

    std::cout << std::endl;

    std::cout << firstElementOfBody->getName() << std::endl;
    std::cout << firstElementOfBody->nextSibling()->getName() << std::endl;
    std::cout << firstElementOfBody->nextSibling()->nextSibling()->getName() << std::endl;

    return 0;
}