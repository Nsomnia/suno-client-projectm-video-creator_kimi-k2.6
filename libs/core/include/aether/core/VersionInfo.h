#pragma once
#include <QString>

namespace aether::core {

struct VersionInfo {
    static constexpr const char* version = "0.1.0";
    static QString gitCommitHash();
    static QString buildDate();
};

} // namespace aether::core
