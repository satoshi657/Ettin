#pragma once
#include "Event.h"


namespace Ettin
{
	class KeyEvent :public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			:m_KeyCode(keycode){}

		int m_KeyCode;

	};
	class KeyDown : public KeyEvent
	{
	public:
		KeyDown(int keycode,int repeatCount)
			: KeyEvent(keycode),m_RepeatCount(repeatCount){}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
		//	std::stringstream ss;
		//	ss << "KeyPressedEvent: " << m_KeyCode << " ( repeat = " <<"repeats)";
		//	return ss.str();
		}
	//	EVENT_CLASS_TYPE(KeyDown);
	private:
		int m_RepeatCount;
	};
};

