#pragma once
#ifndef PAUSEGAMESTATE_HPP
#define PAUSEGAMESTATE_HPP
#include <prg_interactive.hpp>
using namespace prg;
class PauseGameState : public IAppState, public IKeyEvent
{
   public:
   // Implements IAppState
   ~PauseGameState();
   bool onCreate();
   bool onDestroy();
   void onEntry();
   void onExit();
   void onUpdate();
   void onRender( prg::Canvas& canvas );
   // Implements IKeyEventPlayer
   bool onKey( const prg::IKeyEvent::KeyEvent& key_event );
   private:
};
#endif // PAUSEGAMESTATE_HPP
