#pragma once
#include <QString>

namespace aether::core {

class IService {
public:
    virtual ~IService() = default;
    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    virtual QString name() const = 0;
};

} // namespace aether::core
