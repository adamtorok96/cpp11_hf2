#ifndef CPP11_HF2_HTMLPARSER_H
#define CPP11_HF2_HTMLPARSER_H


#include <istream>
#include <memory>

#include "Node.h"

class HTMLParser {
    enum ElementType {OPEN, CLOSE};

    struct Element {
        std::string name;
        ElementType type;
    };

    static std::string getId(std::string const & buffer);

public:
    static std::unique_ptr<Node> parse(std::istream & is);
};


#endif //CPP11_HF2_HTMLPARSER_H
