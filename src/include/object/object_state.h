#ifndef _ANIMATION_H_
#define _ANIMATION_H_


#include "object/object.h"


typedef struct Object_State {
    Object super;
    void (*execute)(struct Object_State *);
} Object_State;


#define Object_State(T) ((Object_State*) (T))


static inline void object_state_update(Object_State * self) {
    self->execute(self);
}


#endif


