#include "Audio.h"

Mix_Chunk *loadSound(string path)
{
    Mix_Chunk *tmp = Mix_LoadWAV(path.c_str());

    if (tmp == nullptr)
    {
        SDL_Log("Failed to load sound. %s", Mix_GetError());
    }

    return tmp;
}
Mix_Music *loadMusic(string path)
{
    Mix_Music *tmp = Mix_LoadMUS(path.c_str());

    if (tmp == nullptr)
    {
        SDL_Log("Failed to load sound. %s", Mix_GetError());
    }

    return tmp;
}

void playSound(string path)
{
    if (sounds[path] == nullptr)
    {
        sounds[path] = loadSound(path);
    }

    Mix_PlayChannel(-1, sounds[path], 0);
}
void playMusic(string path)
{
    if (backgrounds[path] == nullptr)
    {
        backgrounds[path] = loadMusic(path);
    }

    Mix_PlayMusic(backgrounds[path], -1);
}

void pauseMusic()
{
    Mix_PauseMusic();
}

void resumeMusic()
{
    Mix_ResumeMusic();
}

void mute()
{
    //            Mix_Volume()
    Mix_VolumeMusic(0);
    for (auto sound : sounds)
    {
        Mix_VolumeChunk(sound.second, 0);
    }
}
void unMute()
{
    Mix_VolumeMusic(MIX_MAX_VOLUME);
    for (auto sound : sounds)
    {
        Mix_VolumeChunk(sound.second, MIX_MAX_VOLUME);
    }
}

void setVolume(int vol)
{
    Mix_VolumeMusic(vol);
    for (auto sound : sounds)
    {
        Mix_VolumeChunk(sound.second, vol);
    }
}