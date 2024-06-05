#ifndef SPRITE_H
#define SPRITE_H

namespace Genesis {
  struct Sprite {
    int x = 0, y = 0, size = 16;
  };

  namespace Sprites {
    inline Sprite grass = {0, 0};
  }

}

#endif //SPRITE_H
