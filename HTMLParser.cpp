#include <iostream>
#include "HTMLParser.h"

std::string readIs(std::istream & is) {
    std::string buffer;
    char c;

    while(is >> c) {
        buffer += c;
    }

    return buffer;
}

void parseN(std::string const & content) {
    
}

std::unique_ptr<Node> HTMLParser::parse(std::istream & is) {
    std::unique_ptr<Node> root{new Node{}};

    std::string content = readIs(is);

    parseN(content);

    return root;
}

