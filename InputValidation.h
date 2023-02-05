#include <string>
#include <sstream>

class InputValidation
{
  public:
    static bool checkName(const std::string &name)
    {
      if (name.length() == 0 || name[0] == ' ')
        return false;

      for (int i = 0; i < name.length(); i++)
      {
        if (!isalpha(name[i]) && name[i] != ' ')
          return false;
      }
      return true;
    }

    static bool isNumber(const std::string &input)
    {
      for (int i = 0; i < input.size(); i++)
      {
        if (!isdigit(input[i]))
          return false;
      }
      return true;
    }

    static bool checkAge(const int a)
    {
      return a > 0;
    }
    static bool checkGender(const char g)
    {
      return (tolower(g) == 'm' || tolower(g) == 'f');
    }
    static bool checkWeight(const int w)
    {
      return w > 0;
    }
    static bool checkSets(const int s)
    {
      return s > 0;
    }
    static bool checkReps(const int r)
    {
      return r > 0;
    }
};
    