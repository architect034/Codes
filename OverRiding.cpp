#include "bits/stdc++.h"
using namespace std;
class Solve {
  public:
   virtual void _main() {
      cout << "IN Solve\n";
   }
};
class SubSolve : public Solve {
  public:
   virtual void _main() {
      cout << "IN SubSolve\n";
   }
};
class SubSolve2 : public Solve {
  public:
   virtual void _main() {
      cout << "IN SubSolve2\n";
   }
};
int main() {
   Solve *s;
   SubSolve s1;
   SubSolve2 s2;
   s = &s1;
   s->_main();
   s = &s2;
   s->_main();
   s = new Solve();
   s->_main();
}
