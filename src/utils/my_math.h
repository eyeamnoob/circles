#define max(a, b)                \
    ({                           \
        __typeof__(a) __a = (a); \
        __typeof__(b) __b = (b); \
        __a > __b ? __a : __b;   \
    })

#define min(a, b)                \
    ({                           \
        __typeof__(a) __a = (a); \
        __typeof__(b) __b = (b); \
        __a < __b ? __a : __b;   \
    })
