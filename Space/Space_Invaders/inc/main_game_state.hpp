#pragma once
#if !defined MAIN_GAME_STATE_HPP
#define MAIN_GAME_STATE_HPP

#include <prg_interactive.hpp>
#include "spaceship.hpp"
#include "Missile.hpp"
#include "aliens.hpp"

using namespace prg;

class MainGameState : public IAppState, public IKeyEvent
{
   public:
   ~MainGameState();
   bool onCreate();
   bool onDestroy();
   void onEntry();
   void onExit();
   void onUpdate();
   void onRender( prg::Canvas& canvas );
   bool onKey( const prg::IKeyEvent::KeyEvent& key_event );
   private:
   Spaceship spaceship_;
   Missile missile_;
   Aliens alien1_;
   Aliens alien2_;
   Aliens alien3_;
   int frame = 10;

};

#endif // MAIN_GAME_STATE_HPP
