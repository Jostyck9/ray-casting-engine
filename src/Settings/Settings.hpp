#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include <utility>

class Settings
{
private:
  std::pair<unsigned int, unsigned int> _windowSize;
  unsigned int _framerateLimit;
  unsigned int _fov;

public:
  Settings(const std::pair<unsigned int, unsigned int> windowSize = std::pair<unsigned int, unsigned int>(640u, 480u), unsigned int frameRateLimit = 140, unsigned int fov = 60u);

  void setWindowSize(unsigned int width, unsigned int height);

  const std::pair<unsigned int, unsigned int> &getWindowSize();

  void setFramerateLimit(unsigned int frameRateLimit);

  unsigned int getFramerateLimit();
  
  void setFov(unsigned int fov);

  unsigned int getFov();

};

#endif // __SETTINGS_H__