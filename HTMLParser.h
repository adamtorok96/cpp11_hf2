#ifndef CPP11_HF2_HTMLPARSER_H
#define CPP11_HF2_HTMLPARSER_H


#include <istream>
#include <memory>

#include "Node.h"

class HTMLParser {
public:
    static std::unique_ptr<Node> parse(std::istream & is);
};


#endif //CPP11_HF2_HTMLPARSER_H
