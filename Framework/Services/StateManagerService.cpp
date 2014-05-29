/*
 * StateManagerService.cpp
 * n8
 *
 * Author:          Nate Ebel
 * Date:            3/19/14
 * Organization:    n8Tech
 *
 */


#include "StateManagerService.h"
#include "Log.h"

#define TAG "StateManagerService"


n8::StateManagerService::StateManagerService(){
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
bool n8::StateManagerService::RegisterState(EState::Values identifier, State* state){
    map<EState::Values, State*>::iterator ii = m_registeredStates.find(identifier);
    
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
bool n8::StateManagerService::PushState(EState::Values identifier){
    map<EState::Values, State*>::iterator ii = m_registeredStates.find(identifier);
    
    //if there is a matching state to push
    if(ii != m_registeredStates.end()){
        
        //if there is a current state pause it
        if(m_stateStack.size() > 0){
            m_stateStack[m_stateStack.size()-1]->OnPause();
        }
        
        m_stateStack.push_back(ii->second);
        m_stateStack[m_stateStack.size()-1]->OnResume();
        
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
    if (m_stateStack.size() > 1) {
        vector<State*>::iterator ii = m_stateStack.end();
        ii--;
        (*ii)->OnPause();
        m_stateStack.erase(ii);
        
        ii = m_stateStack.end();
        ii--;
        (*ii)->OnResume();
    }
    else if(m_stateStack.size() == 1){
        vector<State*>::iterator ii = m_stateStack.end();
        ii--;
        (*ii)->OnPause();
        m_stateStack.erase(ii);
    }
}

/** Removes all states from the stack
 */
void n8::StateManagerService::Clear(){
    m_stateStack.clear();
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
ID n8::StateManagerService::GetCurrentStateId(){
    if(m_stateStack.size() >= 1){
        //return m_stateStack.top()->GetId();
        return NULL;
    }
    else{
        return NULL;
    }
}

/** Processes a state by handling input events, updating the state logic, 
 *    and rendering the state
 *
 *  @param time The current system time
 *  @param screen The screen canvas for rendering
 *
 */
void n8::StateManagerService::ProcessState(Uint32 time, Window* screen){
    
    if(time > 0 && screen){
    
        if(m_stateStack.size() > 0){
            m_stateStack[m_stateStack.size()-1]->Update(time);
            m_stateStack[m_stateStack.size()-1]->Render(screen);
            
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

void n8::StateManagerService::OnNotify(n8::Event* event){
    if(event->GetType() == EEvents::Values::Exit){
        m_stateStack.clear();
    }
    else if(event->GetType() == EEvents::Values::Test2){
        m_stateStack.push_back(m_registeredStates[EState::Test2]);
    }
}