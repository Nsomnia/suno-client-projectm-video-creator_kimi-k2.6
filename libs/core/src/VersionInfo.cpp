#include "aether/core/VersionInfo.h"

namespace aether::core {

QString VersionInfo::gitCommitHash() {
    return QStringLiteral("unknown");
}

QString VersionInfo::buildDate() {
    return QStringLiteral(__DATE__ " " __TIME__);
}

} // namespace aether::core
