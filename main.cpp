#include <iostream>
#include <fstream>
#include "Node.h"
#include "HTMLParser.h"
#include "Body.h"
#include "Paragraph.h"


int main() {
    std::ifstream is("html.html");

    std::unique_ptr<Node> root{HTMLParser::parse(is)};

    is.close();

//    std::unique_ptr<Node> root{new Node{}};
//    std::unique_ptr<Node> body{new Body{}};
//
//    body->addChild(std::unique_ptr<Node>{new Paragraph{}});
//
//    //root->addChild(std::unique_ptr<Node>(new Body{}));
//    root->addChild(std::move(body));

    root->print();

    std::cout << std::endl;

    root->prettyPrint();

    return 0;
}