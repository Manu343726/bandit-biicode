#ifndef BANDIT_BIIBLOCK_UMBRELLA_H
#define BANDIT_BIIBLOCK_UMBRELLA_H

/*
 * Manu Sánchez 18/09/2014
 */

 /*
  * The bandit block contains the original badit headers in a ./bandit/ subdirecttory. That subdirectory contains the original
  * bandit umbrella header with full path manu343726/bandit/bandit/bandit.h. 
  * What this header located at the root of the block does is to include that original umbrella to allow users to use the common
  * biicode pattern for includes '#include user/blockname/header"', '#include manu343726/bandit/bandit.h"' in this case.
  */

  #include "bandit/bandit.h"

#endif /* BANDIT_BIIBLOCK_UMBRELLA_H */