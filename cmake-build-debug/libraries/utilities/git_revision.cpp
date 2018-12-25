#include <stdint.h>
#include <bears/utilities/git_revision.hpp>

#define BEARS_GIT_REVISION_SHA "cf0174e3ba2f62cdfe9fad359d5c5653e7473fc9"
#define BEARS_GIT_REVISION_UNIX_TIMESTAMP 1545723750
#define BEARS_GIT_REVISION_DESCRIPTION "v0.20.5-51-gcf0174e"

namespace bears { namespace utilities {

const char* const git_revision_sha = BEARS_GIT_REVISION_SHA;
const uint32_t git_revision_unix_timestamp = BEARS_GIT_REVISION_UNIX_TIMESTAMP;
const char* const git_revision_description = BEARS_GIT_REVISION_DESCRIPTION;

} } // end namespace bears::utilities
