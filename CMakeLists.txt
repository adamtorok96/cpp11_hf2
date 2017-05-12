cmake_minimum_required(VERSION 3.7)
project(cpp11_hf2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.h Body.cpp Body.h Paragraph.cpp Paragraph.h UnorderedList.cpp UnorderedList.h ListItem.cpp ListItem.h HTMLParser.cpp HTMLParser.h)
add_executable(cpp11_hf2 ${SOURCE_FILES})