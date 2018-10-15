#include <stdint.h>
#include <bears/utilities/git_revision.hpp>

#define BEARS_GIT_REVISION_SHA "8802a2a89d20b4161bdc556b71d25ba0cb4bbcd7"
#define BEARS_GIT_REVISION_UNIX_TIMESTAMP 1539498223
#define BEARS_GIT_REVISION_DESCRIPTION "v0.20.5-38-g8802a2a"

namespace bears { namespace utilities {

const char* const git_revision_sha = BEARS_GIT_REVISION_SHA;
const uint32_t git_revision_unix_timestamp = BEARS_GIT_REVISION_UNIX_TIMESTAMP;
const char* const git_revision_description = BEARS_GIT_REVISION_DESCRIPTION;

} } // end namespace bears::utilities
