#ifndef __SFMLRENDERER_H__
#define __SFMLRENDERER_H__

#include <SFML/Graphics.hpp>
#include <memory>
#include "IRenderer.hpp"
#include "Settings.hpp"

class SFMLRenderer : public IRenderer
{
private:
  std::shared_ptr<Settings> _settings;
  sf::RenderWindow _window;

public:
  SFMLRenderer(const std::shared_ptr<Settings> &settings);

  void init() override;

  void drawLine(const std::pair<float, float> &start, const std::pair<float, float> &end, float size = 1.f) override;

  void render() override;

  bool isOpen() override;

private:
  void _manageEvents();

  void _drawVertexLine(const sf::Vector2f &start, const sf::Vector2f &end);

  void _drawRect(const sf::Vector2f &start, const sf::Vector2f &end, float size);

  float _getAngle(const sf::Vector2f &end);

  float _norme(const sf::Vector2f &vector);
};

#endif // __SFMLRENDERER_H__