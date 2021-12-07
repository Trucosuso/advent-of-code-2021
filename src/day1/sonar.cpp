#include <fstream>
#include <iostream>
#include <vector>
#include "../helpers/helpers.h"

void
addDataToVector (std::vector<int> &dataVector)
{
  std::string filePath = "data/day1.dat";
  std::string line;
  std::ifstream dataFile;

  askForFilePathIfNeeded(filePath);

  dataFile.open (filePath);

  if (dataFile.is_open ())
    {
      while (std::getline (dataFile, line))
        {
          dataVector.push_back (std::stoi (line));
        }
      dataFile.close ();
    }
}

int
numberOfIncreases (std::vector<int> &vector)
{
  int increases = 0;
  for (auto i = std::begin (vector); i != std::end (vector); ++i)
    {
      auto nextPointer = std::next (i, 1);
      if (*nextPointer > *i)
        {
          ++increases;
        }
    }
  return increases;
}

int
numberOfWindowIncreases (std::vector<int> &vector, int window = 1)
{
  int increases = 0;

  for (auto iterator = vector.begin (); iterator != vector.end () - (window);
       ++iterator)
    {
      int windowSum = 0;
      int nextWindowSum = 0;
      for (int i = 0; i < window; ++i)
        {
          windowSum += *std::next (iterator, i);
          nextWindowSum += *std::next (iterator, i + 1);
        }

      if (nextWindowSum > windowSum)
        {
          ++increases;
        }
    }

  return increases;
}

int
main ()
{
  const int window = 3;
  std::vector<int> depths;
  addDataToVector (depths);

  int increases = numberOfWindowIncreases (depths, window);

  std::cout << increases << std::endl;

  return 0;
}