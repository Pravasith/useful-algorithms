#include "Engineer.h"
#include <filesystem> // C++17 and later
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using std::string;
namespace fs = std::filesystem;

Engineer::Engineer() {
  std::set<string> template_strings = {"<F_NAME>", "<DISCOVERY>",
                                       "<LIKES>",  "<PAGE_LINK>",
                                       "<NO_EXP>", "<NO_EXP_LIKE>"};

  string fName = "fName";
  string discovery = "discovery";
  string likes = "likes";
  string pageLink = "pageLink";
  string noExp = "noExp";
  string noExpLike = "noExpLike";

  const string dirPath = "../../Database/FriendlyMessage.csv";

  string output;

  std::ifstream ifs;
  ifs.open(dirPath);

  if (!fs::exists(dirPath))
    std::cout << "ERROR: The file " << dirPath << " doesn't exist!\n";

  if (!ifs.is_open())
    std::cout << "ERROR: File Not Open" << '\n';
  else {
    string value;
    bool delimiterStart = 0;

    while (ifs.good()) {
      if (delimiterStart) {
        std::getline(ifs, value, '>');

        if (value == "F_NAME") {
          value = fName;
        } else if (value == "DISCOVERY") {
          value = discovery;
        } else if (value == "LIKES") {
          value = likes;
        } else if (value == "PAGE_LINK") {
          value = pageLink;
        } else if (value == "NO_EXP") {
          value = noExp;
        } else if (value == "NO_EXP_LIKE") {
          value = noExpLike;
        }

        delimiterStart = 0;
      } else {
        std::getline(ifs, value, '<');
        delimiterStart = 1;
      }

      output += value;
    }

    std::cout << output << std::endl;
  }
}

Engineer::~Engineer() {}
