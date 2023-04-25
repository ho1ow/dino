#include "Audio.h"

Mix_Chunk *loadSound(const char *path)
{
    Mix_Chunk *tmp = Mix_LoadWAV(path);

    if (tmp == nullptr)
    {
        SDL_Log("Failed to load sound. %s", Mix_GetError());
    }

    return tmp;
}
Mix_Music *loadMusic(const char *path)
{
    Mix_Music *tmp = Mix_LoadMUS(path);

    if (tmp == nullptr)
    {
        SDL_Log("Failed to load sound. %s", Mix_GetError());
    }

    return tmp;
}

void playSound(const char *path)
{
    if (sounds[path] == nullptr)
    {
        sounds[path] = loadSound(path);
    }

    Mix_PlayChannel(-1, sounds[path], 0);
}
void playMusic(const char *path)
{
    if (backgrounds[path] == nullptr)
    {
        backgrounds[path] = loadMusic(path);
        if (backgrounds[path] == nullptr)
        {
            SDL_Log("Failed to play music.");
            return;
        }
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

void muteAudio()
{
    Mix_VolumeMusic(0);
    for (auto sound : sounds)
    {
        Mix_VolumeChunk(sound.second, 0);
    }
}
void unMuteAudio()
{
    Mix_VolumeMusic(MIX_MAX_VOLUME);
    for (auto sound : sounds)
    {
        Mix_VolumeChunk(sound.second, MIX_MAX_VOLUME);
    }
}
