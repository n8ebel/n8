/*
 * StateManagerService.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */

#include "../Headers/Game.h"

#define TAG "StateManagerService"


n8::StateManagerService::StateManagerService(std::shared_ptr<n8::Game> game) : Service(game){
    Log::Info(TAG, "Constructor");
}

/** Virtual destructor
 *  Deletes registered game states
 */
n8::StateManagerService::~StateManagerService(){
    Log::Info(TAG, "Destructor");
}



/** Stores a pointer to a State subclass in a map.
 *  If there are no states currently in the state stack,
 *    the state being added is pushed onto the stack.
 *  If a state with the specified identifier has previously
 *    been added, the new state is not added to the map.
 *
 *  @param identifier An integer identifier for the state.  Used to differentiate states
 *          and to change states.
 *  @param state A pointer to a State subcalss object
 *
 *  @return True if the state was succesffuly stored in the map; False otherwise.
 */
bool n8::StateManagerService::RegisterState(int identifier, std::shared_ptr<n8::State> state){
    map<int, std::shared_ptr<n8::State>>::iterator ii = m_registeredStates.find(identifier);
    
    if(ii == m_registeredStates.end()){
        m_registeredStates[identifier] = state;
        
        return true;
    }
    else{
        
        return false;
    }
    
    
    
}

/** Pushes a new State pointer onto the state stack.
 *  If the identifier hasn't been registered with the system
 *    nothing is pushed onto the stack.
 *
 *  @param identifier The map key for a stored State pointer
 *
 *  @return True if a State was pushed onto the stack, false otherwise.
 *
 */
bool n8::StateManagerService::PushState(std::shared_ptr<n8::State> state){
    //if there is a state to push
    if(state != nullptr){
        
        //if there is a current state pause it
        if(m_stateStack.size() > 0){
            m_stateStack.top()->OnPause();
        }
        
        m_stateStack.push(state);
        ResumeState(state);
        
        return true;
    }
    else{
        
        return false;
    }

}

/** If the state stack isn't empty, the top state is popped off
 *
 */
 
void n8::StateManagerService::PopState(){
    
    if(m_stateStack.size() > 0){
        m_stateStack.top()->OnPause();
        m_stateStack.pop();
    }
    
    if(m_stateStack.size() > 0){
         m_game->getInputService()->RegisterUserInterface(m_stateStack.top()->GetGUI());
        ResumeState(m_stateStack.top());
    }
}

/** Removes all states from the stack
 */
void n8::StateManagerService::Clear(){
    m_stateStack.empty();
}

/** Returns the size of the state stack
 *
 *  @return The integer size of the state stack
 */
int n8::StateManagerService::GetStackSize(){
    return m_stateStack.size();
}

/** Gives access to the identifier of the current state object
 *
 *  @return The ID object of the current state object
 */
ID const * const n8::StateManagerService::GetCurrentStateId(){
    if(m_stateStack.size() >= 1){
        return &m_stateStack.top()->GetId();
    }
    else{
        return nullptr;
    }
}

/** Processes a state by handling input events, updating the state logic, 
 *    and rendering the state
 *
 *  @param time The current system time
 *  @param screen The screen canvas for rendering
 *
 */
void n8::StateManagerService::ProcessState(Uint32 time, const std::shared_ptr<n8::Window> screen){
    
    if(time > 0 && screen){
    
        if(m_stateStack.size() > 0){
            m_stateStack.top()->Update(time);
            m_stateStack.top()->Render();
        }
        
        if(m_stateStack.size() > 0){
            
        }
        
        if(m_stateStack.size() > 0){
            
        }
    }
    else if(time <= 0){
        Log::Error(TAG , "ProcessState(): Game time not greater than 0");
    }
    else if(screen == nullptr){
        Log::Error(TAG , "ProcessState(): Screen pointer is NULL");
    }
}

void n8::StateManagerService::OnNotify(std::shared_ptr<Event> event){ }

void n8::StateManagerService::ResumeState(std::shared_ptr<n8::State> state){
    auto inputService = m_game->getInputService();
    if(inputService == nullptr){
        return;
    }
    
    inputService->RegisterUserInterface(state->GetGUI());
    inputService->RegisterMouseMoveAction( [state](int x, int y){
        state->GetGUI()->CheckMove(x,y);
    });
    
    inputService->RegisterMouseButtonUpAction( [state](int x, int y){
        state->GetGUI()->CheckClickUp(x, y);
        
    });
    
    inputService->RegisterMouseButtonDownAction( [state](int x, int y){
        state->GetGUI()->CheckClickDown(x, y);
    });
    
    state->OnResume();
}