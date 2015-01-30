#include "../inc/spaceship.hpp"
#include <iostream>

using namespace prg;
using namespace std;
Spaceship::~Spaceship()
{
   while(!space_pos_.empty())
   {
      space_pos_.pop_front();
   }
}
void Spaceship::pushback()
{
   int x,y;
   x=space_pos_.back().pos_x_;
   y=space_pos_.back().pos_y_;
   space_pos_.push_back(NodeS(x,y));
}
void Spaceship::pushfront(int x, int y)
{
   space_pos_.push_front(NodeS(x,y));
}
void Spaceship::Edge()
{
   if(x_ <= 0 || x_ >= 765)
   {
      SetDirection(2);
   }
   x_=space_pos_.front().pos_x_;
}
void Spaceship::Life()
{
}
void Spaceship::Draw( Canvas& canvas )
{
   list<NodeS>::const_iterator iterator_;
   ImageFile("space_invader_sprites.bmp").load(sprite);
   for(iterator_ = space_pos_.begin(); iterator_ != space_pos_.end(); ++iterator_)
   {
      canvas.blit(sprite, 1,31,33,59,iterator_->pos_x_,iterator_->pos_y_);
   }
}
void Spaceship::Move()
{
      switch(direction_)
      {
         case 0: //Left
         {
            if (x_ <= 0)
            {

            }
            else
            {
               pushfront(x_-4 , y_);
               space_pos_.pop_back();
            }
         }
         break;
         case 1: //Right
         {
            if (x_ >= 765)
            {

            }
            else
            {
               pushfront(x_+4 , y_);
               space_pos_.pop_back();
            }
         }
         break;
         case 2: //Stop
         {
            pushfront(x_ , y_);
            space_pos_.pop_back();
         }
         break;
      }
   x_=space_pos_.front().pos_x_;
   y_=space_pos_.front().pos_y_;
}
void Spaceship::SetDirection( int direction )
{
   if( direction >= 0 && direction < 3 )
   {
    direction_ = direction;
   }
}
int Spaceship::GetX()
{
   return space_pos_.front().pos_x_;
}
