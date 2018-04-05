#include <iostream>
#include <limits>

using namespace std;

int main()
{
  cout << "Minimum value for char: " << std::numeric_limits<char>::min() << '\n';
  cout << "Maximum value for char: " << std::numeric_limits<char>::max() << '\n';
  int minc = std::numeric_limits<char>::min();
  unsigned maxc = std::numeric_limits<char>::max();
	//cout<<int('a');
  cout << "Minimum value for int: " << minc << '\n';
  cout << "Maximum value for int: " << maxc << '\n';
  cout << "Minimum value for short: " << std::numeric_limits<short>::min() << '\n';
  cout << "Maximum value for short: " << std::numeric_limits<short>::max() << '\n';
  cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
  cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
  cout << "Minimum value for long: " << std::numeric_limits<long>::min() << '\n';
  cout << "Maximum value for long: " << std::numeric_limits<long>::max() << '\n';
  cout << "Minimum value for float: " << std::numeric_limits<float>::min() << '\n';
  cout << "Maximum value for float: " << std::numeric_limits<float>::max() << '\n';
  cout << "Minimum value for double: " << std::numeric_limits<double>::min() << '\n';
  cout << "Maximum value for double: " << std::numeric_limits<double>::max() << '\n';
  cout << "Minimum value for long double: " << std::numeric_limits<long double>::min() << '\n';
  cout << "Maximum value for long double: " << std::numeric_limits<long double>::max() << '\n';
  cout << "Minimum value for unsigned: " << std::numeric_limits<unsigned>::min() << '\n';
  cout << "Maximum value for unsigned: " << std::numeric_limits<unsigned>::max() << '\n';


}
/*
#include <limits>
#include <iostream>
#include <ostream>

int main()
{
    int minc = std::numeric_limits<char>::min();
    unsigned maxc = std::numeric_limits<char>::max();

    std::cout << minc << std::endl;
    std::cout << maxc << std::endl;
}*/
