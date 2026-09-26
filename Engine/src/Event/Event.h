#pragma once
#include "../spch.h"

namespace Six{
	class SIXAPI SEvent {
	public:
		virtual ~SEvent() = default;
		virtual size_t GetTypeId() const = 0;
		template <typename T>
		static size_t StaticTypeId() {
			static size_t id = m_nextid++;
			return id;
		}

		virtual std::string toString() const = 0;
		template <typename T>
		bool is() const { return GetTypeId() == T::StaticTypeId(); }
	private:
		static size_t m_nextid;
	};

	class SIXAPI SWinCloseEvent : public SEvent {
		SELF_ADD_ID(SWinCloseEvent)
	public:
		std::string toString() const override { return "Window Close"; }
	};
}

