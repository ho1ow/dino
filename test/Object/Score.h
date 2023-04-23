#ifndef SCORE_H
#define SCORE_H

#include "../Text/Text.h"
#include <memory>
// #include<string.h>

using std::make_unique;
using std::unique_ptr;

class Score
{
private:
    int64_t hiScore_ = 0;
    float currentScore_ = 0;
    int currentScoreInt = 0;
    const uint SCORE_RATIO = 8;

    int effectCounter = 0;
    const int SCORE_SOUND_INTERVAL = 100;

    SDL_Rect hiScore_r = {0, 0, 200, 100};
    Vector hiScore_p{SCREEN_WIDTH - 400, 20};

    SDL_Rect currentScore_r{0, 0, 100, 100};
    Vector currentScore_p{SCREEN_WIDTH - 150, 20};

public:
    Score();

    unique_ptr<Text> hiScore;
    unique_ptr<Text> currentScore;

    void updateHiScore();

    void reset();
    void update(float time);
    void render();

    uint getScore();
    uint getHiscore();
};

#endif
