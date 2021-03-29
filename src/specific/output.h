#ifndef T1M_SPECIFIC_OUTPUT_H
#define T1M_SPECIFIC_OUTPUT_H

#include <stdint.h>

// clang-format off
#define S_ClearScreen           ((void      (*)())0x0042FCC0)
#define S_OutputPolyList        ((void      (*)())0x0042FD10)
#define S_GetObjectBounds       ((int32_t   (*)(int16_t* bptr))0x0042FD30)
// clang-format on

void S_InitialisePolyList();
int32_t S_DumpScreen();
void S_InitialiseScreen();
void S_CalculateLight(int32_t x, int32_t y, int32_t z, int16_t room_num);
void S_CalculateStaticLight(int16_t adder);
// TODO: replace with S_DrawScreenLine
void S_Draw2DLine(
    int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t z, uint8_t color);
void S_DrawHealthBar(int32_t percent);
void S_DrawAirBar(int32_t percent);
void S_SetupBelowWater(int32_t underwater);
void S_SetupAboveWater(int32_t underwater);
void S_AnimateTextures(int32_t ticks);
void S_DisplayPicture(const char *filename);
void S_DrawLightningSegment(
    int32_t x1, int32_t y1, int32_t z1, int32_t x2, int32_t y2, int32_t z2,
    int32_t width);

int32_t GetRenderScaleGLRage(int32_t unit);
void RenderBar(int32_t value, int32_t value_max, int32_t bar_type);

int32_t GetRenderScale(int32_t unit);
int32_t GetRenderHeightDownscaled();
int32_t GetRenderWidthDownscaled();
int32_t GetRenderHeight();
int32_t GetRenderWidth();

void T1MInjectSpecificOutput();

#endif
