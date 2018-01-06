
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>

void help()
{
  std::cerr << "The executable srt2txt converts srt files into txt ones." << std::endl;
  std::cerr << "Usage: srt2txt [filename]" << std::endl;
}

int main(int argc, char *argv[])
{

  if (argc < 1 or strcmp(argv[1], "-help") == 0)
  {
    help();
    return EXIT_FAILURE;
  }

  std::ifstream file;
  file.open(argv[1]);

  if (not file.is_open())
  {
    std::cerr << "Unable to open file " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  file.close();
  

  

  return EXIT_SUCCESS;
}
