#include <algorithm>
#include "Game.h"

void Game::Init() {
    std::string buffer;

    std::ifstream is(file);

    while( is.good() ) {
        is >> buffer;

        words.push_back(buffer);
    }

    is.close();
}

void Game::Start() {
    char tip;

    while( true ) {
        std::cin >> tip;

        std::cout << "Tip: '" << tip << "'" << std::endl;

        Sieve(tip);

    }
}

void Game::Sieve(char tip) {

    auto c = 0;

    for(auto word : words) {
        if( std::find(word.begin(), word.end(), tip) != word.end() )
            ++c;
    }

}
