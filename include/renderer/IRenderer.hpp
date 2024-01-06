#ifndef __IRENDERER_H__
#define __IRENDERER_H__

#include <utility>

class IRenderer
{
public:
  virtual ~IRenderer() = default;

  virtual void init() = 0;

  virtual void drawLine(const std::pair<float, float> &start, const std::pair<float, float> &end, float size = 1.f) = 0;

  virtual void render() = 0;

  virtual bool isOpen() = 0;
};

#endif // __IRENDERER_H__