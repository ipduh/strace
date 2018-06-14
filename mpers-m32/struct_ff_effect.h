#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
uint16_t type;
int16_t id;
uint16_t direction;
struct {
uint16_t button;
uint16_t interval;
} ATTRIBUTE_PACKED trigger;
struct {
uint16_t length;
uint16_t delay;
} ATTRIBUTE_PACKED replay;
unsigned char mpers_filler_1[2];
union {
struct {
int16_t level;
struct {
uint16_t attack_length;
uint16_t attack_level;
uint16_t fade_length;
uint16_t fade_level;
} ATTRIBUTE_PACKED envelope;
} ATTRIBUTE_PACKED constant;
struct {
int16_t start_level;
int16_t end_level;
struct {
uint16_t attack_length;
uint16_t attack_level;
uint16_t fade_length;
uint16_t fade_level;
} ATTRIBUTE_PACKED envelope;
} ATTRIBUTE_PACKED ramp;
struct {
uint16_t waveform;
uint16_t period;
int16_t magnitude;
int16_t offset;
uint16_t phase;
struct {
uint16_t attack_length;
uint16_t attack_level;
uint16_t fade_length;
uint16_t fade_level;
} ATTRIBUTE_PACKED envelope;
unsigned char mpers_filler_2[2];
uint32_t custom_len;
mpers_ptr_t custom_data;
} ATTRIBUTE_PACKED periodic;
struct {
uint16_t right_saturation;
uint16_t left_saturation;
int16_t right_coeff;
int16_t left_coeff;
uint16_t deadband;
int16_t center;
} ATTRIBUTE_PACKED condition[2];
struct {
uint16_t strong_magnitude;
uint16_t weak_magnitude;
} ATTRIBUTE_PACKED rumble;
} u;
} ATTRIBUTE_PACKED m32_struct_ff_effect;
#define MPERS_m32_struct_ff_effect m32_struct_ff_effect
