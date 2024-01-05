#include "SFMLRenderer.hpp"

void SFMLRenderer::init()
{
  this->_window.create({this->_windowSize.first, this->_windowSize.second}, "RayCasting Engine", sf::Style::Close | sf::Style::Titlebar);
  this->_window.setFramerateLimit(this->_framerateLimit);
}

void SFMLRenderer::drawLine(std::pair<float, float> &start, std::pair<float, float> &end, float size)
{
  sf::Vertex line[] =
      {
          sf::Vertex({start.first, start.second}),
          sf::Vertex({end.first, end.second})};

  this->_window.draw(line, 2, sf::Lines);
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
