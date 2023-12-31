#ifndef __SFMLRENDER_H__
#define __SFMLRENDER_H__

#include <SFML/Graphics.hpp>
#include "IRender.hpp"

class SFMLRender : public IRender
{
private:
  std::pair<unsigned int, unsigned int> _windowSize = {
      200u,
      200u,
  };
  unsigned int _framerateLimit = 144;
  sf::RenderWindow _window;

public:
  void init() override;

  void drawLine(std::pair<float, float> &start, std::pair<float, float> &end, float size = 1.f) override;

  void render() override;

  bool isOpen() override;

private:
  void _manageEvents();
};

#endif // __SFMLRENDER_H__