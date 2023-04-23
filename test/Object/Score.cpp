#include "Score.h"

Score::Score()
{
    this->hiScore = make_unique<Text>("HI 00000", &hiScore_r, hiScore_p);
    this->currentScore = make_unique<Text>("00000", &currentScore_r, currentScore_p);
    soundUpdate = 0;
}
void Score::updateHiScore()
{
    if (hiScore_ == currentScoreInt)
        return;
    if (hiScore_ < currentScoreInt)
    {
        hiScore_ = currentScoreInt - 1;

        char hiStr[6];
        intToStr(currentScoreInt, hiStr, 5);

        std::string tmp = "HI " + std::string(hiStr);
        hiScore->updateText(tmp.c_str());
    }
}
void Score::update(float time)
{
    int tmp = currentScoreInt;
    currentScore_ += time / 1000;
    currentScoreInt = (int)(currentScore_);
    if (tmp == currentScoreInt)
        return;
    char str[6];
    intToStr(currentScoreInt, str, 5);

    static Uint32 lastFrameTime = 0;
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastFrameTime > 75)
    {
        currentScore->updateText(str);
        lastFrameTime = currentTime;
    }
    if (currentScoreInt > 0 && hiScore_ != 0 && currentScoreInt - 1 > hiScore_ && soundUpdate == 0)
    {
        playSound("res/sounds/coin.wav");
        soundUpdate = 1;
    }
}
void Score::render()
{
    hiScore->render();
    currentScore->render();
}
void Score::reset()
{
    currentScore->updateText("00000");
    currentScore_ = 0;
    currentScoreInt = 0;
    soundUpdate = 0;
}
uint Score::getScore()
{
    return currentScoreInt;
}

uint Score::getHiscore()
{
    return hiScore_;
}