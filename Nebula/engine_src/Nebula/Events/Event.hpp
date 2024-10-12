#pragma once
#include "nbpch.hpp"
#include "Nebula/Core/Base.hpp"
#include "spdlog/fmt/ostr.h"

namespace Nebula {

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
        KeyPressed, KeyReleased, KeyTyped,
        AppTick, AppUpdate, AppRender
    };

    enum class EventCategory {
        None = 0,
        Application = BIT(0),
        Input = BIT(1),
        Keyboard = BIT(2),
        Mouse = BIT(3),
        MouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) \
        static EventType GetStaticType() { return EventType::type; } \
        virtual EventType GetEventType() const override { return GetStaticType(); } \
        virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
        virtual int32_t GetCategoryFlags() const override { return static_cast<int32_t>(category); }

    class Event {
    public:
        bool Handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int32_t GetCategoryFlags() const = 0;

        virtual std::string ToString() const {
            return fmt::format("Event: {}, Handled: {}", GetName(), Handled);
        }

        bool IsInCategory(EventCategory category) const {
            return (GetCategoryFlags() & static_cast<int>(category)) != 0;
        }
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        // F will be deduced by the compiler
        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }

}
