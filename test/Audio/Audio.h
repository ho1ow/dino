#ifndef AUDIO_H
#define AUDIO_H

#include "../Utils/CommonVariable.h"
#include <string>
using namespace std;

    static map<string, Mix_Chunk *> sounds{};
    static map<string, Mix_Music *> backgrounds{};

    Mix_Chunk *loadSound(string path);
    Mix_Music *loadMusic(string path);

    void playSound(string path);
    void playMusic(string path);

    void pauseMusic();
    void resumeMusic();
    void mute();
    void unMute();

    void setVolume(int vol);

#endif