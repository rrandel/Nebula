#pragma once

#include "Event.hpp"
#include <type_traits>

namespace Nebula {

    // Bitwise operators for EventCategory
    inline EventCategory operator|(EventCategory lhs, EventCategory rhs) {
        return static_cast<EventCategory>(
            static_cast<std::underlying_type<EventCategory>::type>(lhs) |
            static_cast<std::underlying_type<EventCategory>::type>(rhs)
            );
    }

    inline EventCategory operator&(EventCategory lhs, EventCategory rhs) {
        return static_cast<EventCategory>(
            static_cast<std::underlying_type<EventCategory>::type>(lhs) &
            static_cast<std::underlying_type<EventCategory>::type>(rhs)
            );
    }

    inline EventCategory operator^(EventCategory lhs, EventCategory rhs) {
        return static_cast<EventCategory>(
            static_cast<std::underlying_type<EventCategory>::type>(lhs) ^
            static_cast<std::underlying_type<EventCategory>::type>(rhs)
            );
    }

    inline EventCategory& operator|=(EventCategory& lhs, EventCategory rhs) {
        return lhs = lhs | rhs;
    }

    inline EventCategory& operator&=(EventCategory& lhs, EventCategory rhs) {
        return lhs = lhs & rhs;
    }

    inline EventCategory& operator^=(EventCategory& lhs, EventCategory rhs) {
        return lhs = lhs ^ rhs;
    }

}