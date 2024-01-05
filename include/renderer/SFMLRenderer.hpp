#ifndef __SFMLRENDERER_H__
#define __SFMLRENDERER_H__

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

class SFMLRenderer : public IRenderer
{
private:
  std::pair<unsigned int, unsigned int> _windowSize = {
      600u,
      600u,
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

#endif // __SFMLRENDERER_H__