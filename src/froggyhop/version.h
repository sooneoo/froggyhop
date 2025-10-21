#ifndef _VERSION_H_
#define _VERSION_H_


typedef struct {
    unsigned short major;
    unsigned short minor;
    unsigned short patch;    
} FroggyHop_Version;


#define froggyhop_version() \
    (FroggyHop_Version) {   \
        .major = 0          \
        , .minor = 2        \
        , .patch = 0        \
}

#endif
