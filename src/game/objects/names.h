#pragma once

#include "global/types.h"

// Return a list of object ids that match given string.
// out_match_count may be NULL.
// The result must be freed by the caller.
GAME_OBJECT_ID *Object_IdsFromName(
    const char *name, int32_t *out_match_count, bool (*filter)(GAME_OBJECT_ID));

const char *Object_GetName(const GAME_OBJECT_ID object_id);
