#ifndef __SFMLRENDERER_H__
#define __SFMLRENDERER_H__

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

class SFMLRenderer : public IRenderer
{
private:
  std::pair<unsigned int, unsigned int> _windowSize = {
      640u,
      480u,
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

  void _drawVertexLine(sf::Vector2f &start, sf::Vector2f &end);

  void _drawRect(sf::Vector2f &start, sf::Vector2f &end, float size);

  float _getAngle(sf::Vector2f &end);

  float _norme(sf::Vector2f &vector);
};

#endif // __SFMLRENDERER_H__