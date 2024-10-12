#pragma once

#include "Event.hpp"
#include "EventCategoryOperators.hpp"
#include <Nebula/Core/KeyCodes.hpp>

namespace Nebula {

    class KeyEvent : public Event
    {
    public:
        int32_t GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategory::Keyboard | EventCategory::Input)
    protected:
        KeyEvent(int32_t keycode)
            : m_KeyCode(keycode) {}

        int32_t m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
            : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

        bool IsRepeat() const { return m_IsRepeat; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        bool m_IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int32_t keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent {
    public:
        KeyTypedEvent(int32_t keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };

}
