
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

  // Check the command line

  if (argc < 1 or strcmp(argv[1], "-help") == 0)
  {
    help();
    return EXIT_FAILURE;
  }

  // Try to open the subtitle file (.srt) in reading mode

  std::string srt_filename = argv[1];
  std::ifstream srt_file;
  srt_file.open(srt_filename.c_str());

  if (not srt_file.is_open())
  {
    std::cerr << "Unable to open srt file " << srt_filename << std::endl;
    return EXIT_FAILURE;
  }

  // Try to open the text file (.txt) in writing mode 
  
  std::size_t ext_index = srt_filename.find_last_of("."); 
  std::string txt_filename = srt_filename.substr(0, ext_index) + ".txt"; 
  std::ofstream txt_file(txt_filename.c_str());

  // Convert the srt file into a txt one

  std::string line;
  while (std::getline(srt_file, line))
  {
    std::getline(srt_file, line);
    std::getline(srt_file, line);
    txt_file << line << " ";
    std::getline(srt_file, line);
  } 

  txt_file.close();
  srt_file.close();
  

  

  return EXIT_SUCCESS;
}
