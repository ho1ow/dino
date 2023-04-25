#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>

static std::map<const char *, Mix_Chunk *> sounds{};
static std::map<const char *, Mix_Music *> backgrounds{};

Mix_Chunk *loadSound(const char *path);
Mix_Music *loadMusic(const char *path);

void playSound(const char *path);
void playMusic(const char *path);

void pauseMusic();
void resumeMusic();
void muteAudio();
void unMuteAudio();

void cleanupAudio();

#endif