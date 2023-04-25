#ifndef SCORE_H
#define SCORE_H

#include "../Text/Text.h"
#include "../Audio/Audio.h"
#include <memory>

using std::make_unique;
using std::unique_ptr;

class Score
{

private:
    int hiScore_ = 0;
    float currentScore_ = 0;
    int currentScoreInt = 0;
    int soundUpdate ;

    SDL_Rect hiScore_r = {0, 0, 140, 40};
    Vector hiScore_p{SCREEN_WIDTH - 320, 20};

    SDL_Rect currentScore_r{0, 0, 100, 40};
    Vector currentScore_p{SCREEN_WIDTH - 150, 20};

public:
    Score();
    ~Score();
    unique_ptr<Text> hiScore;
    unique_ptr<Text> currentScore;

    void updateHiScore();
    void intToStr(int num, char *str, int width)
    {
        snprintf(str, width + 1, "%0*d", width, num);
    }
    void reset();
    void update(float time);
    void render();

    float getScore();
    uint getHiscore();
};

#endif
