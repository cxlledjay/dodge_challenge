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
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 1, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_ENEMY_TRUCK    }
};

const spawn_entry_t _SP_alpha_2[] =
{
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 1, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       }
};

const spawn_entry_t _SP_alpha_3[] =
{
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 1, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       }
};

const spawn_entry_t _SP_alpha_4[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR1    , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_ENEMY_CAR2    },
	{.is_last = 0, .left = MOT_ENEMY_BIKE    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_CAR2    , .right = MOT_NULL       },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_ENEMY_BIKE    , .right = MOT_ENEMY_CAR1    },
	{.is_last = 0, .left = MOT_ENEMY_CAR1    , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_NULL       , .mid = MOT_NULL       , .right = MOT_ENEMY_TRUCK    },
	{.is_last = 0, .left = MOT_ENEMY_CAR2    , .mid = MOT_ENEMY_CAR1    , .right = MOT_NULL       },
	{.is_last = 1, .left = MOT_ENEMY_BIKE    , .mid = MOT_NULL       , .right = MOT_NULL       }
};


/// --------------------------------------- < for official release > ---------------------------------------

const spawn_entry_t _SP_heavy_traffic[] =
{
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK }
};

const spawn_entry_t _SP_fast_section[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        }
};

const spawn_entry_t _SP_missile_action[] =
{
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ABILITY_MISSILE, .mid = MOT_ABILITY_MISSILE, .right = MOT_ABILITY_MISSILE},
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        }
};

const spawn_entry_t _SP_rare_refuel[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_FUELCAN     , .mid = MOT_FUELCAN     , .right = MOT_FUELCAN     },
	{.is_last = 0, .left = MOT_FUELCAN     , .mid = MOT_FUELCAN     , .right = MOT_FUELCAN     },
	{.is_last = 0, .left = MOT_FUELCAN     , .mid = MOT_FUELCAN     , .right = MOT_FUELCAN     },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        }
};

const spawn_entry_t _SP_missile_madness[] =
{
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_ABILITY_MISSILE, .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_ABILITY_MISSILE, .mid = MOT_ENEMY_BIKE  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ABILITY_MISSILE, .mid = MOT_ABILITY_MISSILE, .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ABILITY_MISSILE, .mid = MOT_ENEMY_CAR2  , .right = MOT_ABILITY_MISSILE},
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_ENEMY_BIKE  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ABILITY_MISSILE},
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_ABILITY_MISSILE, .right = MOT_ABILITY_MISSILE},
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ABILITY_MISSILE},
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  }
};

const spawn_entry_t _SP_casual_traffic_1[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        }
};

const spawn_entry_t _SP_casual_traffic_2[] =
{
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 1, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        }
};

const spawn_entry_t _SP_casual_traffic_3[] =
{
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 1, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        }
};

const spawn_entry_t _SP_casual_traffic_4[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        }
};

const spawn_entry_t _SP_bikers[] =
{
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_ENEMY_BIKE  },
	{.is_last = 1, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        }
};

const spawn_entry_t _SP_zig_zag1[] =
{
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ENEMY_BIKE  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR2  , .right = MOT_ENEMY_CAR1  },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_ENEMY_CAR2  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_ENEMY_CAR2  },
	{.is_last = 1, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_NULL        }
};

const spawn_entry_t _SP_zig_zag2[] =
{
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_BIKE  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_BIKE  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 0, .left = MOT_ENEMY_CAR1  , .mid = MOT_NULL        , .right = MOT_ENEMY_CAR2  },
	{.is_last = 0, .left = MOT_NULL        , .mid = MOT_ENEMY_CAR1  , .right = MOT_NULL        },
	{.is_last = 1, .left = MOT_ENEMY_CAR2  , .mid = MOT_NULL        , .right = MOT_ENEMY_TRUCK }
};




/************************************************************
 * testing purposes
 ************************************************************/

/* #define DEBUG */

#ifdef DEBUG
const spawn_entry_t _SP_DEBUG_ONLY[] =
{
	{.is_last = 0, .left = MOT_NULL    			, .mid = MOT_NULL       		, .right = MOT_ENEMY_CAR1   		},
	{.is_last = 0, .left = MOT_NULL    			, .mid = MOT_NULL       		, .right = MOT_ENEMY_CAR2       	},
	{.is_last = 0, .left = MOT_NULL    			, .mid = MOT_NULL       		, .right = MOT_ENEMY_TRUCK    		},
	{.is_last = 0, .left = MOT_NULL    			, .mid = MOT_NULL       		, .right = MOT_ENEMY_BIKE       	},
	{.is_last = 0, .left = MOT_FUELCAN    		, .mid = MOT_FUELCAN       		, .right = MOT_FUELCAN    			},
	{.is_last = 0, .left = MOT_EXTRALIFE    	, .mid = MOT_EXTRALIFE       	, .right = MOT_EXTRALIFE      		},
	{.is_last = 0, .left = MOT_ABILITY_MISSILE  , .mid = MOT_ABILITY_MISSILE    , .right = MOT_ABILITY_MISSILE  	},
	{.is_last = 1, .left = MOT_NULL    			, .mid = MOT_NULL       		, .right = MOT_NULL       			}
};
#endif


/************************************************************
 * connecting all spawn patterns to indexed interface for rng
 ************************************************************/

const spawn_entry_t * const SPAWN_PATTERN_PTR_COLLECTION[SPAWN_PATTERNS_CNT] =
{
 	#ifdef DEBUG
	_SP_DEBUG_ONLY,
	_SP_DEBUG_ONLY,
	_SP_DEBUG_ONLY,
	_SP_DEBUG_ONLY
	#else
    _SP_alpha_1,
    _SP_alpha_2,
    _SP_alpha_3,
    _SP_alpha_4,
	_SP_heavy_traffic,
	_SP_fast_section,
	_SP_missile_action,
	_SP_rare_refuel,
	_SP_missile_madness,
	_SP_casual_traffic_1,
	_SP_casual_traffic_2,
	_SP_casual_traffic_3,
	_SP_casual_traffic_4,
	_SP_bikers,
	_SP_zig_zag1,
	_SP_zig_zag2
	#endif
};