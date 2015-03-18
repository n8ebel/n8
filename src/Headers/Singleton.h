#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
    /** \class Singleton
     *  \brief Template for singleton classes
     */
class Singleton{

public:
	static shared_ptr<T> GetInstance(){
        if (!m_instance){
			m_instance.reset(new T());
		}
        
        return m_instance;
	}

protected:
	static shared_ptr<T> m_instance;

};

template<class T> shared_ptr<T> Singleton<T>::m_instance(nullptr);

#endif