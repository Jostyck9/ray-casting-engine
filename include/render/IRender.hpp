#ifndef __IRENDER_H__
#define __IRENDER_H__

#include <utility>

class IRender
{
public:
  virtual ~IRender() = default;

  virtual void init() = 0;

  virtual void drawLine(std::pair<float, float> &start, std::pair<float, float> &end, float size = 1.f) = 0;

  virtual void render() = 0;

  virtual bool isOpen() = 0;
};

#endif // __IRENDER_H__