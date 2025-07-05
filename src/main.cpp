#include <algorithm>
#include <chrono>
#include <iostream>
#include <format>
#include <string>
#include <tuple>
#include <cstdlib>

#include "commands_list.h"
#include "matrix.h"

int calculate_levenshtein_distnce(const std::string &input_string,
                                  const std::string_view &target_string)
{
  Matrix2d d(input_string.size() + 1, target_string.size() + 1);

  // todo: can probably improve this

  for (int i = 0; i <= input_string.size(); i++)
  {
    d(i, 0) = i;
  }

  for (int j = 1; j <= target_string.size(); j++)
  {
    d(0, j) = j;
  }

  for (int i = 1; i <= input_string.size(); i++)
  {
    for (int j = 1; j <= target_string.size(); j++)
    {
      int deletion = d(i - 1, j) + 1;
      int insertion = d(i, j - 1) + 1;
      int substitution = d(i - 1, j - 1) +
                         (input_string[i - 1] == target_string[j - 1] ? 0 : 1);

      int distance = std::min({deletion, insertion, substitution});

      if (i > 1 && j > 1 && input_string[i - 1] == target_string[j - 2] &&
          input_string[i - 2] == target_string[j - 1])
      {
        distance = std::min(distance, d(i - 2, j - 2) + 1);
      }

      d(i, j) = distance;
    }
  }

  return d(input_string.size(), target_string.size());
}

// std::vector<std::string>&

std::tuple<std::string, std::string> read_args(int argc, char *argv[])
{
  std::string command{""};
  std::string args{""};

  for (int i = 0; i < argc; i++)
  {
    if (i == 1)
    {
      command = std::string(argv[i]);
    }

    if (i > 1)
    {
      if (std::find(flags_with_quotes.begin(), flags_with_quotes.end(),
                    argv[i - 1]) != flags_with_quotes.end())
      {
        args += "\"" + std::string(argv[i]) + "\" ";
      }
      else
      {
        args += std::string(argv[i]) + " ";
      }
    }
  }

  return {command, args};
}

int main(int argc, char *argv[])
{
  auto [command_entered, command_arguments] = read_args(argc, argv);

  auto start = std::chrono::high_resolution_clock::now();
  int min_dist = 1000;
  std::string most_similar_command;
  for (std::string_view command : commands)
  {
    // todo: re-add this when analysing performance
    // if (abs(command.size() - command_entered.size()) > 2) {
    //     continue;
    // }
    int result = calculate_levenshtein_distnce(command_entered, command);
    if (result < min_dist)
    {
      min_dist = result;
      most_similar_command = command;
    }
  }
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::cout << "result is " << most_similar_command << " took "
            << duration.count() << "us" << std::endl
            << "args are: " << command_arguments << std::endl;

  std::system(std::format("git {} {}",
                          most_similar_command, command_arguments)
                  .c_str());

  return 0;
}