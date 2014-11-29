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

#include "SDL2/SDL.h"
#include "ID.h"
#include "Service.h"
#include "State.h"
#include "Window.h"



namespace n8{
    
class StateManagerService : public Service{
    
public:
    StateManagerService(std::shared_ptr<n8::Game>);
    ~StateManagerService();
    
    
    bool RegisterState(int identifier, State* state);
    
    bool PushState(n8::State*);
    void PopState();
    void Clear();
    
    int GetStackSize();
    ID GetCurrentStateId();
    
    void ProcessState(Uint32 time, Window* screen);
    
    void OnNotify(std::shared_ptr<Event>) override;
    
private:
    
    
    map<int, State*> m_registeredStates; /** < map of identifiers and game state objects */
    stack<State*> m_stateStack; /** < stack of state objects */
    
    void ResumeState(State*);
    
};

}

#endif
