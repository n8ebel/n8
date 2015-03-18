/*
 * StateManagerService.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */

#ifndef STATE_MANAGER_SERVICE_H
#define STATE_MANAGER_SERVICE_H

#include <map>
#include <vector>
#include <stack>

#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"

#include "Window.h"
#include "Service.h"
#include "State.h"


namespace n8{
    
class StateManagerService : public Service{
    
public:
    StateManagerService(std::shared_ptr<n8::Game>);
    ~StateManagerService();
    
    
    bool RegisterState(int identifier, std::shared_ptr<n8::State> state);
    
    bool PushState(std::shared_ptr<n8::State>);
    void PopState();
    void Clear();
    
    int GetStackSize();
    ID const* const GetCurrentStateId();
    
    void ProcessState(Uint32 time, const std::shared_ptr<n8::Window> screen);
    
    void OnNotify(std::shared_ptr<Event>) override;
    
private:
    
    
    map<int, std::shared_ptr<n8::State> > m_registeredStates; /** < map of identifiers and game state objects */
    stack<std::shared_ptr<n8::State> > m_stateStack; /** < stack of state objects */
    
    void ResumeState(std::shared_ptr<n8::State>);
    
};

}

#endif
