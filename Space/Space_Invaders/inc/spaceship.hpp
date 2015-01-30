#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <string>
#include <iostream>
#include <prg_interactive.hpp>
#include <list>

using namespace std;
using namespace prg;

class NodeS;

class Spaceship
{
   public:
   ~Spaceship();
   void pushback();
   void pushfront(int x, int y);
   bool empty_() const
   {
      return space_pos_.size() == 0;
   }
   unsigned int sizl ()
   {
      return space_pos_.size();
   }
   void SetDirection( int direction );
   void Edge();
   void Life();
   void Draw( prg::Canvas& canvas );
   void Move();
   int GetDirection_(){return direction_;}
   int GetX();
   int x_;
   int y_;
   private:
   Image sprite;
   
   unsigned int direction_;
   list<NodeS> space_pos_;
};
/*--------------------------------------------------------------
                           NODE
----------------------------------------------------------------*/
class NodeS
{
   public:
    NodeS(int x, int y)
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
   friend class Spaceship;
   int pos_x_;
   int pos_y_;

};
#endif // SPACESHIP_HPP
