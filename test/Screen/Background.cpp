#include "Background.h"

Background::Background()
{

    cloud = new Cloud(sheet);
    road = new Road(sheet);
}
Background::~Background()
{
    delete cloud;
    delete road;
}
void Background::setBgColor(SDL_Color color)
{
    // Only set the color if it has changed
    if (color.r != COLOR.r || color.g != COLOR.g || color.b != COLOR.b || color.a != COLOR.a)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer);
        COLOR = color;
    }
}
void Background::setNight(SDL_Color color)
{
    if (color.r > night.r)
    {
        color.r -= change;
    }
    if (color.g > night.g)
    {
        color.g -= change;
    }
    if (color.b > night.b)
    {
        color.b -= change;
    }
    if (color.r == night.r && color.g == night.g && color.b == night.b)
    {
        isNight = true;
        isDay = false;
    }
}
void Background::setDay(SDL_Color color)
{
    if (color.r < day.r)
    {
        color.r += change;
    }
    if (color.g < day.g)
    {
        color.g += change;
    }
    if (color.b < day.b)
    {
        color.b += change;
    }
    if (color.r == day.r && color.g == day.g && color.b == day.b)
    {
        isDay = true;
        isNight = false;
    }
}

void Background::update()
{
    cloud->update();
    road->update(road->getRect());
    road->set_speed(4);
    if (isNight)
    {
        setNight(COLOR);
    }
    if (isDay)
    {
        setDay(COLOR);
    }
}
void Background::renderCloudAndRoad(SDL_Renderer *renderer)
{
    cloud->render(renderer, cloud->getRect());
    road->renderScroll(renderer, road->getRect());
}

void Background::renderBg(SDL_Renderer *renderer)
{
    // setBgColor(color);
    renderCloudAndRoad(renderer);
}
