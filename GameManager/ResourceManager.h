//
// Created by hiepd on 1/20/2022.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Singleton.h"
#include "bits/stdc++.h"
#include "../GameConfig.h"

using namespace sf;
using namespace std;
#define DATA ResourceManager::getInstance()

class ResourceManager : public Singleton<ResourceManager> {
public:
        ResourceManager();
        ~ResourceManager();

        void addTexture(string name);
        void removeTexture(string name);
        Texture* getTexture(string name);

        void addFont(string name);
        void removeFont(string name);
        Font* getFont(string name);

        void addSound(string name);
        void removeSound(string name);
        Sound* getSound(string name);

        void addMusic(string name);
        void removeMusic(string name);
        Music* getMusic(string name);

        void playMusic(string name);
        void playSound(string name);
        void setAllowSound(bool allow);

private:
    map<string, Texture*> m_MapTexture;
    map<string, Font*> m_MapFont;
    map<string, Sound*> m_MapSound;
    map<string, Music*> m_MapMusic;

    string m_Path;
    string m_TexturePath;
    string m_FontPath;
    string m_SoundPath;

    bool m_AllowSound;
};


#endif //GAME_RESOURCEMANAGER_H
