#include "game_include/data/spawn_pattern.h"



/************************************************************
 * empty spawn pattern for stage transitions
 ************************************************************/

const spawn_entry_t SP_empty[1] =
{
	{.is_last = 1, .left = MOT_NULL    , .mid = MOT_NULL       , .right = MOT_NULL    }
};



/************************************************************
 * all spawn patterns
 ************************************************************/

const spawn_entry_t _SP_alpha_1[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 1, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    }
};

const spawn_entry_t _SP_alpha_2[] =
{
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 1, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       }
};

const spawn_entry_t _SP_alpha_3[] =
{
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 1, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       }
};

const spawn_entry_t _SP_alpha_4[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 1, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       }
};




/************************************************************
 * connecting all spawn patterns to indexed interface for rng
 ************************************************************/

const spawn_entry_t * const SPAWN_PATTERN_PTR_COLLECTION[SPAWN_PATTERNS_CNT] =
{
    _SP_alpha_1,
    _SP_alpha_2,
    _SP_alpha_3,
    _SP_alpha_4,
};