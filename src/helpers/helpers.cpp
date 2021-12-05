#include "helpers.h"
#include <filesystem>
#include <iostream>

void
askForFilePathIfNeeded (std::string &filePath)
{
  while (!std::filesystem::exists (filePath))
    {
      std::cout << filePath
                << " does not exists. Type the route to the data file"
                << std::endl;
      std::cin >> filePath;
    }
}