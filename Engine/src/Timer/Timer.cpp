#include "spch.h"
#include "Timer.h"

namespace Six {
	bool STimer::Init() {
		m_start = std::chrono::steady_clock::now();
		deltatime = 0.0f;
		nowtime = 0.0f;
		lasttime = 0.0f;
		m_counter = 0;
		return true;
	}

	void STimer::Update() {
		auto current = std::chrono::steady_clock::now();
		nowtime = std::chrono::duration<float>(current - m_start).count();
		deltatime = nowtime - lasttime;
		lasttime = nowtime;
		if (m_setfps > 0.f) {
			auto sleepMs = std::chrono::milliseconds(1000 / (int)m_setfps);
			std::this_thread::sleep_for(sleepMs);
			current = std::chrono::steady_clock::now();
			nowtime = std::chrono::duration<float>(current - m_start).count();
			deltatime = nowtime - lasttime;
			lasttime = nowtime;
		}
		if (deltatime > 1e-6f) m_fps = 1.f / deltatime;
		else m_fps = 0.f;
	}

	void STimer::Reset() {
		m_start = std::chrono::steady_clock::now();
		deltatime = 0.0f;
		nowtime = 0.0f;
		m_counter = 0;
	}

	std::vector<int> STimer::GetNowTime() {
		std::vector<int> res;
		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		std::tm tm_buf{};
		localtime_s(&tm_buf, &t);
		res.push_back(tm_buf.tm_year + 1900);
		res.push_back(tm_buf.tm_mon);
		res.push_back(tm_buf.tm_mday);
		res.push_back(tm_buf.tm_hour);
		res.push_back(tm_buf.tm_min);
		res.push_back(tm_buf.tm_sec);
		res.push_back(tm_buf.tm_wday);
		res.push_back(tm_buf.tm_yday);
		res.push_back(tm_buf.tm_isdst);
		return res;
	}
}