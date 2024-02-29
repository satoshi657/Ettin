#pragma once

#define BTT(x) (1 << x)

namespace Ettin
{
	enum class EventType
	{
		None = 0,
		Quit,
		KeyDown, KeyUp,
		MouseMoved, MouseScrolled, MouseButtonDown, MouseButtonUp
	};
	enum EventCategory
	{
		None = 0,
		EventCategoryInput = BTT(0),
		EventCategoryKeyboard = BTT(1),
		EventCategoryMouse = BTT(2),
		EventCategoryMouseButton = BTT(3),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type}\
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) const
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	public:

	};
	class EventDispatcher
	{

	};
}

