#include "Score.h"

Score::Score()
{

    this->hiScore = make_unique<Text>("HI 00000", &hiScore_r, hiScore_p);
    // hiScore->setRect(&hiScore_r);
    // hiScore->setTextPos(hiScore_p);
    this->currentScore = make_unique<Text>("0", &currentScore_r, currentScore_p);
}
void Score::updateHiScore()
{
    if (hiScore_ < currentScore_)
    {
        hiScore_ = (int64_t)currentScore_;

        std::string hiStr = std::to_string(hiScore_);

        std::string tmp = "HI" + hiStr;
        hiScore->updateText(tmp.c_str());
    }
}
void Score::update(float time)
{

    currentScore_ += time * SCORE_RATIO;
    currentScoreInt = (uint)(currentScore_);
    std::string text = std::to_string(currentScoreInt);

    // padding 0

    currentScore->updateText(text.c_str());

    if (currentScoreInt > 0 &&
        currentScoreInt % SCORE_SOUND_INTERVAL == 0 &&
        currentScore_ - currentScoreInt < (5.0f / SCORE_SOUND_INTERVAL))
    { // frame time, to it work properly
      // AudioManager::playSound(Constants::sounds.coin);
      // effectCounter = 50;
    }

    if (effectCounter > 0)
    {
        effectCounter--;
    }
}
void Score::render()
{
    std::cerr << "Rendering score..." << std::endl;
    std::cerr << "Current score: " << currentScoreInt << std::endl;
    std::cerr << "High score: " << hiScore_ << std::endl;

    std::cerr << "hiScore rect: x=" << hiScore->getRect()->x
              << ", y=" << hiScore->getRect()->y
              << ", w=" << hiScore->getRect()->w
              << ", h=" << hiScore->getRect()->h << std::endl;

    std::cerr << "currentScore rect: x=" << currentScore->getRect()->x
              << ", y=" << currentScore->getRect()->y
              << ", w=" << currentScore->getRect()->w
              << ", h=" << currentScore->getRect()->h << std::endl;

    std::cerr << "hiScore pos: x=" << hiScore->getPos().x
              << ", y=" << hiScore->getPos().y << std::endl;

    std::cerr << "currentScore pos: x=" << currentScore->getPos().x
              << ", y=" << currentScore->getPos().y << std::endl;

    // check if the position of the score objects is within the game window
    if (hiScore->getPos().x + hiScore->getRect()->w  > SCREEN_WIDTH)
    {
        std::cerr << "Warning: hiScore is offscreen to the right!" << std::endl;
    }

    if (hiScore->getPos().y + hiScore->getRect()->h  > SCREEN_HEIGHT)
    {
        std::cerr << "Warning: hiScore is offscreen below!" << std::endl;
    }

    if (currentScore->getPos().x + currentScore->getRect()->w > SCREEN_WIDTH)
    {
        std::cerr << "Warning: currentScore is offscreen to the right!" << std::endl;
    }

    if (currentScore->getPos().y + currentScore->getRect()->h  > SCREEN_HEIGHT)
    {
        std::cerr << "Warning: currentScore is offscreen below!" << std::endl;
    }

    hiScore->render();
    currentScore->render();
}
void Score::reset()
{
    currentScore->updateText("00000");
    currentScore_ = 0;
    currentScoreInt = 0;
}
uint Score::getScore()
{
    return (uint)(currentScore_);
}

uint Score::getHiscore()
{
    return hiScore_;
}