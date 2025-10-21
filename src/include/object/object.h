#ifndef _OBJECT_H_
#define _OBJECT_H_


#include <raylib.h>


typedef struct Object {
    void (*draw)(struct Object *);
    Vector2 (*size)(struct Object *);
    Vector2 (*position)(struct Object *);
} Object;


#define OBJECT(T) ((Object*) (T))


static inline void object_draw(Object * self) {
    self->draw(self);
}


static inline Vector2 object_size(Object * self) {
    return self->size(self);
}


static inline Vector2 object_position(Object * self) {
    return self->position(self);
}


#endif


