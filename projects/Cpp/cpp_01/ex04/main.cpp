#include <iostream>
#include <string>
#include <fstream>


std::string sub_line(const std::string &s1, const std::string &s2, const std::string &line)
{
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result.append(line.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(line.substr(pos));
    return result;
}


int main(int argc, char **argv){
    if (argc != 4)
    {
        std::cout << "incorrect amount of params\n";
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.length() == 0 || s2.length() == 0)
    {
        std::cout << "Error strings cannot be empty\n";
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout <<"infile cannot be opened\n";
        return (1);
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cout <<"outfile cannot be opned\n";
        return (1);
    }
    std::string line;
    while (getline(infile, line))
        outfile << sub_line(s1, s2, line) << "\n";
    
    return (0);
}
