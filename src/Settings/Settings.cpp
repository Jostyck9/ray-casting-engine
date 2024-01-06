#include "Settings.hpp"

Settings::Settings(const std::pair<unsigned int, unsigned int> windowSize, unsigned int frameRateLimit, unsigned int fov)
{
  this->_windowSize = windowSize;
  this->_framerateLimit = frameRateLimit;
  this->_fov = fov;
}

void Settings::setFov(unsigned int fov)
{
  this->_fov = fov;
}

unsigned int Settings::getFov()
{
  return this->_fov;
}

void Settings::setWindowSize(unsigned int width, unsigned int height)
{
  this->_windowSize = std::pair<unsigned int, unsigned int>(width, height);
}

const std::pair<unsigned int, unsigned int> &Settings::getWindowSize()
{
  return this->_windowSize;
}

void Settings::setFramerateLimit(unsigned int frameRateLimit)
{
  this->_framerateLimit = frameRateLimit;
}

unsigned int Settings::getFramerateLimit()
{
  return this->_framerateLimit;
}
