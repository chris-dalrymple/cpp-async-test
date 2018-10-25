#ifndef CONNECTION_H
#define CONNECTION_H

#include <atomic>

namespace System {
    class Connection {
        public:
            void waitForConnection(std::atomic<bool>*);
    };
}

#endif // CONNECTION_H
