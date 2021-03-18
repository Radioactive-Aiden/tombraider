#ifndef T1M_SPECIFIC_FILE_H
#define T1M_SPECIFIC_FILE_H

#include <stdint.h>
#include <stdio.h>

// clang-format off
// TODO: these can be removed once entire file.c is ported, but currently
// we're still passing FILE* pointers to the original game routines and if we
// mix our version of libc with the game's, the game will read garbage.
#define _fopen                  ((FILE*         (*)(const char  *path, const char *mode))0x00442EE0)
#define _fseek                  ((int32_t       (*)(FILE* fp, int32_t offset, int32_t mode))0x00443000)
#define _fclose                 ((int32_t       (*)(FILE* fp))0x00442B40)
#define _fread                  ((size_t        (*)(void *, size_t, size_t, FILE *))0x00442C20)
// clang-format on

int32_t LoadLevel(const char *filename, int32_t level_num);
int32_t LoadRooms(FILE *fp);
int32_t LoadObjects(FILE *fp);
int32_t LoadSprites(FILE *fp);
int32_t LoadItems(FILE *fp);
int32_t LoadDepthQ(FILE *fp);
int32_t LoadPalette(FILE *fp);
int32_t LoadCameras(FILE *fp);
int32_t LoadSoundEffects(FILE *fp);
int32_t LoadBoxes(FILE *fp);
int32_t LoadAnimatedTextures(FILE *fp);
int32_t LoadCinematic(FILE *fp);
int32_t LoadDemo(FILE *fp);
int32_t LoadSamples(FILE *fp);
int32_t LoadTexturePages(FILE *fp);
int32_t S_LoadLevel(int32_t level_num);
const char *GetFullPath(const char *filename);

int32_t GetSecretCount();

void T1MInjectSpecificFile();

#endif
