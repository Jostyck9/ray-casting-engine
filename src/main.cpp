#define _USE_MATH_DEFINES

#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "IRender.hpp"
#include "SFMLRender.hpp"

static const Config CONFIG = {
    {64},
    std::vector<std::vector<char>>{
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    }};

std::pair<float, float> getEndPosition(const std::pair<float, float> &start, float direction)
{
  auto degree = direction * (M_PI / 180);

  return std::pair<float, float>{start.first + (cosf(degree) * 50), start.second + (sinf(degree) * 50)};
}

int main()
{
  auto speed = 50.f;
  auto direction = 0.f;
  std::pair<float, float> start{100.f, 100.f};
  sf::Clock clock;
  std::unique_ptr<IRender> render = std::make_unique<SFMLRender>();

  render->init();

  while (render->isOpen())
  {
    auto gameTick = clock.getElapsedTime();
    clock.restart();

    direction += speed * gameTick.asSeconds();
    auto end = getEndPosition(start, direction);
    render->drawLine(start, end);

    render->render();
  }
}