#ifndef MISSILE_HPP
#define MISSILE_HPP

#include <prg_interactive.hpp>
#include <list>
#include <iostream>

using namespace prg;
using namespace std;

class NodeM;

class Missile
{
   public:
      ~Missile();
      void pushfront(int x, int y);
      void pushback();
      bool empty_() const
      {
         return Missiles_.size() == 0;
      }
      int sizl ()
      {
         return Missiles_.size();
      }
      void move_();
      void draw(prg::Canvas& canvas);
      void destroy();
      void SetDirection(int direction);
      int GetX();
      int GetY();

   private:
      Image sprite;
      list<NodeM> Missiles_;
      int x_;
      int y_;
      unsigned int direction_;

};
class NodeM
{
   public:
    NodeM(int x, int y)
    {
       pos_x_=x;
       pos_y_=y;
    }
    int getX() const
    {
    return pos_x_;
    }
    int getY() const
    {
      return pos_y_;
    }
   private:
   friend class Missile;
   int pos_x_;
   int pos_y_;

};
#endif // MISSILE_HPP
