#define _USE_MATH_DEFINES

#include <cmath>
#include "SFMLRenderer.hpp"

void SFMLRenderer::init()
{
  this->_window.create({this->_windowSize.first, this->_windowSize.second}, "RayCasting Engine", sf::Style::Close | sf::Style::Titlebar);
  this->_window.setFramerateLimit(this->_framerateLimit);
}

void SFMLRenderer::drawLine(std::pair<float, float> &start, std::pair<float, float> &end, float size)
{
  if (size > 1)
  {
    this->_drawRect(sf::Vector2f(start.first, start.second), sf::Vector2f(end.first, end.second), size);
    return;
  }
  this->_drawVertexLine(sf::Vector2f(start.first, start.second), sf::Vector2f(end.first, end.second));
}

void SFMLRenderer::render()
{
  this->_manageEvents();
  _window.display();
  _window.clear();
}

bool SFMLRenderer::isOpen()
{
  return this->_window.isOpen();
}

void SFMLRenderer::_manageEvents()
{
  sf::Event event;

  while (this->_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      this->_window.close();
    }
  }
}

void SFMLRenderer::_drawVertexLine(sf::Vector2f &start, sf::Vector2f &end)
{
  sf::Vertex line[] = {sf::Vertex(start), sf::Vertex(end)};

  this->_window.draw(line, 2, sf::Lines);
}

void SFMLRenderer::_drawRect(sf::Vector2f &start, sf::Vector2f &end, float size)
{
  sf::RectangleShape rectangle({sqrtf(powf(end.x - start.x, 2) + powf(end.y - start.y, 2)), size});

  rectangle.setFillColor(sf::Color::White);
  rectangle.setOrigin({0, size / 2});
  rectangle.setRotation(this->_getAngle(sf::Vector2f(end.x - start.x, end.y - start.y)));
  rectangle.setPosition(start);
  this->_window.draw(rectangle);
}

float SFMLRenderer::_getAngle(sf::Vector2f &end)
{
  sf::Vector2f start(1, 0);

  auto uv = (start.x * end.x) + (start.y * end.y);
  auto normeS = this->_norme(start);
  auto normeE = this->_norme(end);
  auto angleRadiant = acosf(uv / (normeS * normeE));
  auto angle = angleRadiant * 180 / M_PI;
  if (end.y < 0) {
    angle *= -1;
  }
  return angle;
}

float SFMLRenderer::_norme(sf::Vector2f &vector)
{
  return sqrtf(powf(vector.x, 2) + powf(vector.y, 2));
}
