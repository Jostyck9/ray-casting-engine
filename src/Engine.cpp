#define _USE_MATH_DEFINES

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Engine.hpp"

Engine::Engine(std::shared_ptr<IRenderer> &render)
{
  this->_renderer = render;
}

void Engine::start()
{
  auto speed = 50.f;
  auto direction = 0.f;
  std::pair<float, float> start{320.f, 240.f};
  sf::Clock clock;

  this->_renderer->init();
  while (this->_renderer->isOpen())
  {
    auto gameTick = clock.getElapsedTime();
    clock.restart();

    direction += speed * gameTick.asSeconds();
    auto end = this->_getEndPosition(start, direction);
    this->_renderer->drawLine(start, end, 50);

    this->_renderer->render();
  }
}

std::pair<float, float> Engine::_getEndPosition(const std::pair<float, float> &start, float direction)
{
  auto degree = direction * (M_PI / 180);

  return std::pair<float, float>{start.first + (cosf(degree) * 200), start.second + (sinf(degree) * 200)};
}
