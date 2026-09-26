#include "spch.h"
#include "EventQueue.h"

namespace Six {
	size_t SEvent::m_nextid = 0;

	void SEventQueue::Push(SEvent* e) {
		m_events.emplace_back(e);
	}
	void SEventQueue::Clear() {
		m_events.clear();
	}
	size_t SEventQueue::Size() {
		return m_events.size();
	}
	bool SEventQueue::Empty() {
		return m_events.empty();
	}
	std::vector<const SEvent*> SEventQueue::Filter(std::function<bool(const SEvent&)> predicate) {
		std::vector<const SEvent*> res;

		// 2. 使用 const auto& 遍历智能指针，避免拷贝
		for (const auto& e : m_events) { 
			if (!e) continue;

			// 3. 解引用智能指针，获取 SEvent& 传入断言
			if (predicate(*e)) {
				// 4. 存储裸指针（借用，不涉及所有权转移）
				res.push_back(e.get());
			}
		}
		return res;
	}
}