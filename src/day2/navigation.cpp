#include "../helpers/helpers.h"
#include "submarine/submarine.h"
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

std::tuple<std::string, int>
parseStringCommand (std::string stringCommand, std::string separator)
{
  size_t separatorPosition = stringCommand.find_first_of (separator);
  if (separatorPosition == std::string::npos)
    {
      return { "", 0 };
    }

  std::string command = stringCommand.substr (0, separatorPosition);
  int number = std::stoi (stringCommand.substr (separatorPosition + 1));

  return { command, number };
}

void
navigateWithSubmarine (Submarine &submarine, std::string filePath)
{
  std::ifstream dataFile;
  std::string line;

  dataFile.open (filePath);

  if (dataFile.is_open ())
    {
      while (std::getline (dataFile, line))
        {
          auto command = parseStringCommand (line, " ");
          std::string commandType = get<0> (command);

          if (commandType == "forward")
            {
              submarine.forward (get<1> (command));
            }
          else if (commandType == "down")
            {
              submarine.down (get<1> (command));
            }
          else if (commandType == "up")
            {
              submarine.up (get<1> (command));
            }
          else
            {
              std::cerr << "Command " << commandType << " not found"
                        << std::endl;
            }
        }
      dataFile.close ();
    }
}

int
main ()
{
  std::string filePath = "data/day2.dat";

  Submarine mySubmarine (0, 0);

  askForFilePathIfNeeded (filePath);

  navigateWithSubmarine (mySubmarine, filePath);

  std::cout << "Horizontal position: " << mySubmarine.getX () << std::endl;
  std::cout << "Depth: " << mySubmarine.getY () << std::endl;
  std::cout << "Multiplication: " << mySubmarine.getY () * mySubmarine.getX ()
            << std::endl;

  return 0;
}
