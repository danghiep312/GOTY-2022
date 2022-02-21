//
// Created by hiepd on 1/20/2022.
//

#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    m_Path = "Data/";
    m_TexturePath = m_Path + "Textures/";
    m_FontPath = m_Path + "Fonts/";
    m_SoundPath = m_Path + "Sounds/";
    m_AllowSound = true;
}

ResourceManager::~ResourceManager() {
    for (auto it: m_MapTexture) {
        if (it.second != nullptr) {
            delete it.second;
        }
    }
    m_MapTexture.clear();

    for (auto it: m_MapFont) {
        if (it.second != nullptr) {
            delete it.second;
        }
    }
    m_MapFont.clear();
}

void ResourceManager::addTexture(string name) {
    Texture *texture = new Texture();
    texture->loadFromFile(m_TexturePath + name + ".png");

    auto it = m_MapTexture.find(name);
    if (it != m_MapTexture.end()) {
        return;
    }
    m_MapTexture.insert(pair<string, Texture *>(name, texture));
}

void ResourceManager::removeTexture(string name) {
    auto it = m_MapTexture.find(name);
    if (it == m_MapTexture.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapTexture.erase(it);
}

Texture *ResourceManager::getTexture(string name) {
    auto it = m_MapTexture.find(name);
    if (it != m_MapTexture.end()) {
        return it->second;
    }
    Texture *texture = new Texture();
    texture->loadFromFile(m_TexturePath + name + ".png");
    m_MapTexture.insert(pair<string, Texture *>(name, texture));
    return texture;
}

void ResourceManager::addFont(string name) {
    Font *font = new Font();
    font->loadFromFile(m_FontPath + name + ".ttf");

    auto it = m_MapFont.find(name);
    if (it != m_MapFont.end()) {
        return;
    }
    m_MapFont.insert(pair<string, Font *>(name, font));
}

void ResourceManager::removeFont(string name) {
    auto it = m_MapFont.find(name);
    if (it == m_MapFont.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapFont.erase(it);
}

Font *ResourceManager::getFont(string name) {
    auto it = m_MapFont.find(name);
    if (it != m_MapFont.end()) {
        return it->second;
    }
    Font *font = new Font();
    font->loadFromFile(m_FontPath + name + ".ttf");
    m_MapFont.insert(pair<string, Font *>(name, font));
    return font;
}

void ResourceManager::addSound(string name) {
    Sound *sound = new Sound();
    SoundBuffer *buffer = new SoundBuffer();
    buffer->loadFromFile(m_SoundPath + name + ".wav");
    sound->setBuffer(*buffer);

    auto it = m_MapSound.find(name);
    if (it != m_MapSound.end()) {
        return;
    }
    m_MapSound.insert(pair<string, Sound *>(name, sound));
}

void ResourceManager::removeSound(string name) {
    auto it = m_MapSound.find(name);
    if (it == m_MapSound.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapSound.erase(it);
}

Sound *ResourceManager::getSound(string name) {
    auto it = m_MapSound.find(name);
    if (it != m_MapSound.end()) {
        return it->second;
    }

    Sound *sound = new Sound();
    SoundBuffer *buffer = new SoundBuffer();
    buffer->loadFromFile(m_SoundPath + name + ".wav");
    sound->setBuffer(*buffer);
    m_MapSound.insert(pair<string, Sound *>(name, sound));
    return sound;
}

void ResourceManager::addMusic(string name) {
    Music *music = new Music();
    music->openFromFile(m_SoundPath + name + ".wav");

    auto it = m_MapFont.find(name);
    if (it != m_MapFont.end()) {
        return;
    }
    m_MapMusic.insert(pair<string, Music *>(name, music));
}

void ResourceManager::removeMusic(string name) {
    auto it = m_MapMusic.find(name);
    if (it == m_MapMusic.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    m_MapMusic.erase(it);
}

Music *ResourceManager::getMusic(string name) {
    auto it = m_MapMusic.find(name);
    if (it != m_MapMusic.end()) {
        return it->second;
    }
    Music *music = new Music();
    music->openFromFile(m_SoundPath + name + ".wav");
    m_MapMusic.insert(pair<string, Music *>(name, music));
    return music;
}

void ResourceManager::playMusic(string name) {
    if (m_AllowSound) DATA->getMusic(name)->play();
}

void ResourceManager::playSound(string name) {
    if (m_AllowSound) DATA->getSound(name)->play();
}

void ResourceManager::setAllowSound(bool allow) {
    m_AllowSound = allow;
}


