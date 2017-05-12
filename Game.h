#ifndef CPP11_HF2_GAME_H
#define CPP11_HF2_GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Game {
    std::vector<std::string> words;
    std::vector<char> tips;

    std::string file;

    void Sieve(char tip);
public:
    Game(std::string file) : file{file} {}

    void Init();
    void Start();
};


#endif //CPP11_HF2_GAME_H
