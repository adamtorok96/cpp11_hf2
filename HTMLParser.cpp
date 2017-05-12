#include <iostream>
#include <queue>
#include "HTMLParser.h"
#include "Body.h"
#include "Paragraph.h"
#include "UnorderedList.h"
#include "ListItem.h"

std::string HTMLParser::getId(std::string const &buffer) {
    size_t start = buffer.find("id=\"");

    if( start == std::string::npos )
        return std::string();

    start += 4;
    size_t end = buffer.find("\"", start);

    if( end == std::string::npos )
        return std::string();

    return buffer.substr(start, end - start);
}

std::shared_ptr<Node> HTMLParser::parse(std::istream & is) {
    std::shared_ptr<Node> root{new Node{}};
    std::queue<Element> queue;

    Element element;
    element.type = OPEN;

    bool start = false;
    char c;

    while(is >> c) {
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

    std::string id;

    Node * last = root.get();
    Node * node = nullptr;

    while( !queue.empty() ) {
        element = queue.front();

        id = getId(element.name);

        if( element.name.find("body") == 0 ) {
            if( element.type == OPEN ) {
                node = new Body;
                
                last->addChild(node, id);
                last = node;
            } else {
                last = last->getParent().lock().get();
            }
        }
        else if( element.name.find("p") == 0 ) {
            if( element.type == OPEN ) {
                node = new Paragraph;

                last->addChild(node, id);
                last = node;
            } else {
                last = last->getParent().lock().get();
            }
        }
        else if( element.name.find("ul") == 0 ) {
            if( element.type == OPEN ) {
                node = new UnorderedList;

                last->addChild(node, id);
                last = node;
            } else {
                last = last->getParent().lock().get();
            }
        }
        else if( element.name.find("li") == 0 ) {
            if( element.type == OPEN ) {
                node = new ListItem;

                last->addChild(node, id);
                last = node;
            } else {
                last = last->getParent().lock().get();
            }
        }

        queue.pop();
    }

    return root;
}