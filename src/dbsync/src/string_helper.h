#pragma once
#include <string>
#include <sstream>

class StringHelper {
  public:
  static bool replace_string(std::string& data, const std::string& to_search, const std::string& to_replace) {
    
    auto pos {data.find(to_search)};
    const auto ret_val { std::string::npos != pos };
    while (std::string::npos != pos) {
      data.replace(pos, to_search.size(), to_replace);
      pos = data.find(to_search, pos + to_replace.size());
    }
    return ret_val;
  }

  static std::vector<std::string> split(const std::string& s, char delimiter)
  {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
      tokens.push_back(token);
    }
    return tokens;
  }
};