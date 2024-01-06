#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <memory>
#include "IRenderer.hpp"
#include "Settings.hpp"

class Engine
{
private:
  std::shared_ptr<IRenderer> _renderer;
  std::shared_ptr<Settings> _settings;

public:
  Engine(const std::shared_ptr<IRenderer> &renderer, const std::shared_ptr<Settings> &settings);

  void start();

private:
  std::pair<float, float> _getEndPosition(const std::pair<float, float> &start, float direction);
};

#endif // __ENGINE_H__