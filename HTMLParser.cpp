#include <iostream>
#include <queue>
#include "HTMLParser.h"
#include "Body.h"
#include "Paragraph.h"
#include "UnorderedList.h"
#include "ListItem.h"

enum ElementType {OPEN, CLOSE};

struct Element {
    std::string name;
    ElementType type;
};

std::unique_ptr<Node> HTMLParser::parse(std::istream & is) {
    std::unique_ptr<Node> root{new Node{}};
    std::queue<Element> queue;

    Element element;
    element.type = OPEN;

    bool start = false;
    char c;

    while(is >> c) {
        std::cout << c;

        if( c == '<' ) {
            start = true;
        }
        else if( c == '>' ) {
            start = false;

            queue.push(element);

            element.name.clear();
            element.type = OPEN;
        }
        else if( start ) {
            if( c == '/' )
                element.type = CLOSE;
            else
                element.name += c;
        }
    }

    std::cout << std::endl;

    Node * last = root.get();
    Node * node;

    while( !queue.empty() ) {
        element = queue.front();
        std::cout << element.name << " " << element.type << std::endl;

        if( element.name.compare("body") == 0 ) {
            if( element.type == OPEN ) {
                node = new Body;

                last->addChild(node);
                last = node;

                std::cout << last << std::endl;
            } else {
                last = last->getParent();
            }
        }
        else if( element.name.compare("p") == 0 ) {
            if( element.type == OPEN ) {
                node = new Paragraph;

                last->addChild(node);
                last = node;
            } else {
                last = last->getParent();
            }
        }
        else if( element.name.compare("ul") == 0 ) {
            if( element.type == OPEN ) {
                node = new UnorderedList;

                last->addChild(node);
                last = node;
            } else {
                last = last->getParent();
            }
        }
        else if( element.name.compare("li") == 0 ) {
            if( element.type == OPEN ) {
                node = new ListItem;

                last->addChild(node);
                last = node;
            } else {
                last = last->getParent();
                std::cout << "last: " << last->getName() << std::endl;
            }
        }

        queue.pop();
    }

    return root;
}

