/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** my_cat
*/

#include <iostream>
#include <fstream>

void printFile(const std::string& path)
{ 
    std::string c;
    std::ifstream file;

    file.open(path, std::ios::in);
    if (!file) {
        std::cerr << "my_cat: " << path << ": No such file or directory\n";
        return;
    }
    c = file.get();
    while (file.good()) {
        std::cout << c;
        c = file.get();
    }
    file.close();
}

int main(int argc, char** argv) 
{ 
    if (argc == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]\n";
        return (0);
    }
  
    for (int i = 1; i < argc; ++i) {
        printFile(argv[i]);
    }
  
    return (0); 
} 