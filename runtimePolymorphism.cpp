#include <bits/stdc++.h>
using namespace std;
class Figure {
  public:
   static int data;
   void setData(int d);
   int getData();
   void draw() {
      cout << "Drawing Figure\n";
   }
};
int Figure::data = 10;
void Figure::setData(int d) {
   data = d;
};
int Figure::getData() {
   return data;
}
class Rectangle : public Figure {
  public:
   int side;
   void draw() {
      cout << "Drawing Rectangle\n";
   }
};
class Circle : public Figure {
  public:
   void draw() {
      cout << "Drawing Circle\n";
   }
};
class Triangle : public Figure {
  public:
   void draw() {
      cout << "Drawing Triangle\n";
   }
};
int main() {
   Figure *t = new Triangle();
   Figure obj;
   cout << obj.getData() << "\n";
   obj.setData(27);
   cout << obj.getData() << "\n";
   obj.draw();
   Figure *f = new Rectangle();
   f->draw();
   Circle c;
   f = &c;
   f->draw();
   return 0;
}