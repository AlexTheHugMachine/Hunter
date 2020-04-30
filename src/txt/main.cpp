#include <iostream>
#include "Menu.h"
#include "txtGame.h"
#include "WinTxt.h"

using namespace std;

int main(void)
{
  Menu mn;
  mn.display();
  unsigned int m;
  std::cout << "What do you want to do? indicate the corresponding figure" << endl;
  std::cin >> m;
  mn.action(m);
  return 0;
}
