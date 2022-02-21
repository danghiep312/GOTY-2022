//
// Created by hiepd on 1/20/2022.
//

#ifndef GAME_SINGLETON_H
#define GAME_SINGLETON_H

template <class T>
class Singleton {
private:
    static T* s_Instance;
protected:
    Singleton() {}
    virtual ~Singleton() {
        delete s_Instance;
    }
public:
    static T* getInstance() {
        if (s_Instance == nullptr) {
            s_Instance = new T();
        }
        return s_Instance;
    }

    static bool hasInstance() {
        return s_Instance != 0;
    }

    static void freeInstance() {
        if (s_Instance) {
            delete s_Instance;
        }
    }
};

template<class T> T* Singleton<T>::s_Instance = nullptr;

#endif //GAME_SINGLETON_H
